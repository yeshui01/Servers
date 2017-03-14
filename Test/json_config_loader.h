#ifndef __JSON_CONFIG_LOADER_H__
#define __JSON_CONFIG_LOADER_H__
#include "json/json.h"
#include <string>
#include <iostream>
#include <fstream>
class JsonConfigLoader
{
public:
	JsonConfigLoader();
	~JsonConfigLoader();
	bool LoadFile(std::string file_name);
	virtual bool LoadRowData(const Json::Value &row_data);
};


#endif // __JSON_CONFIG_LOADER_H__