/*=============================================================================
#    Copyright (c) 2015
#    ShanghaiKunyan.  All rights reserved
#
#    Filename     : mysql_db_pool.h
#    Author       : Tianyiheng
#    Email        : 
#    Date         : 2016-06-14 13:40
#    Description  : 
=============================================================================*/

#ifndef __TYH_SERVERBASE_DB_MYSQL_POOL_H__
#define __TYH_SERVERBASE_DB_MYSQL_POOL_H__

#include <list>
#include <string>
#include <map>
#include <utility>

#include "mysql_connection.h"  
#include "mysql_driver.h"  
#include "statement.h"  
#include "prepared_statement.h"
#include "boost/thread/mutex.hpp"

using namespace sql;


namespace tyh_db {

class MySqlConfig {
 public:
   MySqlConfig() {pool_size_ = 0;}
   ~MySqlConfig() {}
 
  void set_host(std::string const &s) {
    host_ = s;
  } 
  std::string const & host() const {return host_;}

  void set_port(int port) {port_ = port;}
  int port() const  {return port_;}

  void set_user(std::string const & s) {
    user_ = s;  
  } 
  std::string const & user() const {return user_;}  
  
  void set_pswd(std::string const& s) {
    pswd_ = s;
  }
  std::string const& pswd() const {return pswd_;}

  void set_dbname(std::string const &s) {dbname_ = s;}
  std::string const& dbname() const {return dbname_;}

  void set_pool_size(size_t pool_size) {pool_size_ = pool_size;}
  size_t pool_size() const {return pool_size_;}
  size_t pool_size() {return pool_size_;}
 private:
  std::string host_;
  int port_;
  std::string user_;
  std::string pswd_;
  std::string dbname_;
  size_t pool_size_;
};

// -----------------------[mysql connect pool]------------------
class MySqlConnPool {
 public:
  MySqlConnPool();
  ~MySqlConnPool();
  bool Init(MySqlConfig const & db_config);
  
  void PushEngine(sql::Connection * sql_conn_pt);
  sql::Connection * PopEngine();

  void Release();
 protected:
  
 protected:
  std::list<sql::Connection*> engine_list_;
  MySqlConfig db_config_; 
  boost::mutex ls_mutex_;
};

// --------------------------[mysql multi pool]------------------
class MySqlMultiPool {
 public:
   MySqlMultiPool();
   ~MySqlMultiPool();
  
  void InitPool(int pool_id, MySqlConfig const & db_config);
  void Release();
  sql::Connection* GetEngine(int pool_id);
  void RecycleEngine(int pool_id, sql::Connection* conn_pt);
 protected:
  
 protected:
  std::map<int, MySqlConnPool *> map_mysql_pool_;
  // mutex
  boost::mutex map_mutex_;
};


// ------------------------------[multipool raii]---------------------------
class MultiPoolRaiiMySqlEngine {
 public:
  explicit MultiPoolRaiiMySqlEngine(int pool_id, MySqlMultiPool* multi_pool_pt);
  ~MultiPoolRaiiMySqlEngine();
  sql::Connection* GetEngine() { return engine_pt_; }
 private:
  int pool_id_;
  sql::Connection* engine_pt_;
  MySqlMultiPool* multi_mysql_pool_pt_;
};

// -------------------------------[micro define]------------------------------------

#define AUTO_MYSQL_POOL_ENGINE_USE(MultipullPtr, PoolID, LOCAL_ENGINE_VAR) \
 tyh_db::MultiPoolRaiiMySqlEngine auto_raii(PoolID, MultipullPtr); \
 sql::Connection* LOCAL_ENGINE_VAR = auto_raii.GetEngine();

}  // namespace tyh



#endif  // __TYH_SERVERBASE_DB_MYSQL_POOL_H__
