/*=============================================================================
#    Copyright (c) 2015
#    ShanghaiKunyan.  All rights reserved
#
#    Filename     : /home/tyh/project/test_wookong/northsea/restful/pub/sqldbpool/mysql_db_pool.cc
#    Author       : Tianyiheng
#    Email        : tianyiheng@kunyan-inc.com
#    Date         : 2016-06-14 13:49
#    Description  : 
=============================================================================*/
#include <cassert>
#include "tmysqlpool/tmysql_db_pool.h"


namespace  tyh_db {

MySqlConnPool::MySqlConnPool() {
  
}

MySqlConnPool::~MySqlConnPool() {
    Release();
}

bool MySqlConnPool::Init(MySqlConfig const & db_config) {
  boost::mutex::scoped_lock lock(ls_mutex_);
  mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
  for (size_t i = 0; i < db_config.pool_size(); ++i) {
	sql::Connection* con = driver->connect(db_config.host().c_str(), db_config.user().c_str(), db_config.pswd().c_str());
	//sql::Connection* con = driver->connect("localhost", "root", "123456");
	if (NULL != con) {
	  std::string sql_st = "use ";
	  sql_st += db_config.dbname();
	  Statement *state = con->createStatement();
	  if (NULL != state) {
		state->execute(sql_st.c_str());
		delete state, state = NULL;
	  }
	  engine_list_.push_back(con);
	}
  }

  db_config_ = db_config;
  return true;
}


void MySqlConnPool::PushEngine(sql::Connection * sql_conn_pt){
  if (NULL == sql_conn_pt) {
	return;
  }
  boost::mutex::scoped_lock lock(ls_mutex_);
  engine_list_.push_back(sql_conn_pt);
}

sql::Connection * MySqlConnPool::PopEngine() {
  boost::mutex::scoped_lock lock(ls_mutex_);
  if (engine_list_.empty()) {
	return NULL;
  }
  sql::Connection * conn_pt = engine_list_.front();
  engine_list_.pop_front();
  return conn_pt;
}

void MySqlConnPool::Release() {
  boost::mutex::scoped_lock lock(ls_mutex_);
  for (std::list<sql::Connection*>::iterator it = engine_list_.begin(); \
	it != engine_list_.end(); ++it) {
	sql::Connection* conn_pt = *it;
	if (NULL != conn_pt) {
	  conn_pt->close();
	  delete conn_pt, conn_pt = NULL;
	}
  }
  engine_list_.clear();
}

// -----------------------------------------------[mysql multi pool]--------------------
MySqlMultiPool::MySqlMultiPool() {
   
}

MySqlMultiPool::~MySqlMultiPool() {
  Release();
}

void MySqlMultiPool::InitPool(int pool_id, MySqlConfig const & db_config) {
  boost::mutex::scoped_lock lock(map_mutex_);

  std::map<int, MySqlConnPool *>::iterator it = map_mysql_pool_.find(pool_id);
  if (it == map_mysql_pool_.end()) {
    MySqlConnPool *pool_pt = new MySqlConnPool;
    if (NULL != pool_pt) {
      pool_pt->Init(db_config);
      map_mysql_pool_.insert(std::make_pair(pool_id, pool_pt));
    }
  }
}

void MySqlMultiPool::Release() {
  boost::mutex::scoped_lock lock(map_mutex_);
  std::map<int, MySqlConnPool *>::iterator it = map_mysql_pool_.begin();
  for (; it != map_mysql_pool_.end(); ++it) {
    MySqlConnPool * pool_pt  = it->second;
    if (NULL != pool_pt) {
      pool_pt->Release();
      delete pool_pt, pool_pt = NULL;
    }
  }
  map_mysql_pool_.clear();
  
}
//
sql::Connection* MySqlMultiPool::GetEngine(int pool_id) {
  sql::Connection* engine_pt = NULL;
  std::map<int, MySqlConnPool *>::iterator it = map_mysql_pool_.find(pool_id);
  if (it != map_mysql_pool_.end()) {
    MySqlConnPool * pool_pt = it->second;
    if (NULL != pool_pt) {
      engine_pt = pool_pt->PopEngine(); 
    }
  }
  return engine_pt;
}

void MySqlMultiPool::RecycleEngine(int pool_id, sql::Connection* engine_pt) {
  std::map<int, MySqlConnPool *>::iterator it = map_mysql_pool_.find(pool_id);
  if (it != map_mysql_pool_.end()) {
    MySqlConnPool * pool_pt = it->second;
    if (NULL != pool_pt) {
      pool_pt->PushEngine(engine_pt);
    }
  }
}


// -------------------------------------------[mysql pool raii]----------------------------
MultiPoolRaiiMySqlEngine::MultiPoolRaiiMySqlEngine(int pool_id, MySqlMultiPool* multi_pool_pt) {
  engine_pt_ = NULL;
  multi_mysql_pool_pt_ = NULL;
  pool_id_ = 0;
  if (NULL != multi_pool_pt) {
    multi_mysql_pool_pt_ = multi_pool_pt;
    engine_pt_ = multi_mysql_pool_pt_->GetEngine(pool_id);
    pool_id_ = pool_id;
  } 
}

MultiPoolRaiiMySqlEngine::~MultiPoolRaiiMySqlEngine() {
  if (NULL != multi_mysql_pool_pt_) {
    if (NULL != engine_pt_) {
      multi_mysql_pool_pt_->RecycleEngine(pool_id_, engine_pt_); 
    }
  }
}

}  //  namespace tyh
