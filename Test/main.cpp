#include <iostream>
#include "tlog/tboost_log.h"
#include "json/json.h"
#include "json_config_loader.h"
#include "test.pb.h"

class MyConfigManager : public JsonConfigLoader
{
	public:
	MyConfigManager()
	{}
	~MyConfigManager()
	{}
	virtual bool LoadRowData(const Json::Value &row_data);
};

bool MyConfigManager::LoadRowData(const Json::Value &row_data)
{
	std::cout << "ID:" << row_data["ID"].asInt() << std::endl;
	std::cout << "field2Name:" << row_data["field2"]["name"].asString() << std::endl;
	return true;
}

int main(int argc, char* argv[])
{
	TBoostLogger::InitLogger("Test");
	std::cout << "this is used for test ..." << std::endl;
	LOGGER(INFO) << "this is [INFO] log";
	LOGGER(DEBUG) << "this is [DEBUG] log";
	LOGGER(NOTIFY) << "this is [NOTIFY] log";
	LOGGER(WARNNIG) << "this is [WARNNIG] log";
	LOGGER(ERR) << "this is [ERROR] log";
	
	MyConfigManager myconfig;
	myconfig.LoadFile("config_test.txt");

	LOGGER(INFO) << "TEST GOOGLE PROTOBUF";
	protos::TestData pb_data;
	pb_data.set_id(1);
	pb_data.set_name("Tom");
	LOGGER(DEBUG) << "id:" << pb_data.id() << ", name:" << pb_data.name();
	return 0;
}
