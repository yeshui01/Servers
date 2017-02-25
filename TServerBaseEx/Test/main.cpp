#include <iostream>
#include "../tlog/tboost_log.h"

int main(int argc, char* argv[])
{
	TBoostLogger::InitLogger("main");
	std::cout << "this is used for test ..." << std::endl;
	LOGGER(INFO) << "this is [INFO] log";
	LOGGER(DEBUG) << "this is [DEBUG] log";
	LOGGER(NOTIFY) << "this is [NOTIFY] log";
	LOGGER(WARNNIG) << "this is [WARNNIG] log";
	LOGGER(ERR) << "this is [ERROR] log";
	return 0;
}
