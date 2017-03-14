#include "json_config_loader.h"


JsonConfigLoader::JsonConfigLoader()
{

}

JsonConfigLoader::~JsonConfigLoader()
{

}

bool JsonConfigLoader::LoadFile(std::string file_name)
{
	std::ifstream infile;
	infile.open(file_name);
	if (!infile.is_open())
	{
		std::cerr << "打开文件失败[" << file_name << "]" << std::endl;
		return false;
	}
	Json::Reader reader;
	Json::Value root;
	int ret = reader.parse(infile, root, false);
	if (-1 == ret)
	{
		std::cerr << "解析文件 [" << file_name << "] 失败" << std::endl;
		return false;
	}
	for (Json::UInt i = 0; i < root.size(); ++i)
	{
		const Json::Value& row_data_obj = root[i];
		LoadRowData(row_data_obj);
	}
	infile.close();
	return true;
}

bool JsonConfigLoader::LoadRowData(const Json::Value &row_data)
{
	return true;
}