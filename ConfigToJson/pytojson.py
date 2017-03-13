#encoding=utf-8
import os;
import sys;
import string;
import xlrd;

#分割字符串，返回字段列表
def SplitObjStrField(objstr):
	"分割字符串，返回字段映射表"
	fieldlist = objstr.split(';');
	return fieldlist;

#根据字段列表，返回字典映射表
def ConstructFieldDictFromFiledList(fieldlist):
	fielddict = {}
	for i in range(0, len(fieldlist)):
		fieldstr = fieldlist[i].split(':');
		fielddict[fieldstr[0]] = fieldstr[1];
	return fielddict;
	
def GetJsonObjStr(configstr):
	'''根据规定格式的对象配置字符串，
	生成json格式的字符串'''
	configstr = configstr[1:len(configstr)-1];
	fieldlist = SplitObjStrField(configstr);
	fielddict = ConstructFieldDictFromFiledList(fieldlist);
	#根据字段字典表，生成json对象
	index = 0;
	
	jstr =  "{"
	for key in fielddict.keys():
		if (index > 0):
			jstr = jstr +  ","
		index = index + 1;
		format = "\"%s\":\"%s\"";
		values = (key, fielddict[key]);
		tmp = format % values;
		jstr = jstr + tmp;
	jstr = jstr + "}"
	return jstr;
	
	
#根据规定格式的字符串，返回对应的值
def GetValueFromStr(formatstr):
	substr = formatstr.split('=');
	#值类型-值
	valuetype = substr[0];
	value = substr[1];
	if (valuetype == "n"):
		return value;
	elif (valuetype == "s") :
		val = "\"%s\"" % value;
		return val;
	return value;
	
def GetValueType(valuestr):
	substr = valuestr.split('=');
	return substr[0];
#########################################
#由字符串构造一个json对象字符串数据
#########################################
def ObjStrToJsonStr(configstr):
	'''根据规定格式的对象配置字符串，
	生成json格式的字符串'''
	configstr = configstr[1:len(configstr)-1];
	fieldlist = SplitObjStrField(configstr);
	fielddict = ConstructFieldDictFromFiledList(fieldlist);
	#根据字段字典表，生成json对象
	index = 0;
	jsonstr = "{"
	for key in fielddict.keys():
		if (index > 0):
			jsonstr = jsonstr + ","
		index = index + 1;
		format = "\"%s\":%s";
		vtype = GetValueType(fielddict[key]);
		val = ""
		if (vtype == "o"):
			subval = fielddict[key];
			#print "subval=", subval;
			#val = ObjStrToJsonStr(subval);
		else:
			val = GetValueFromStr(fielddict[key]);
		values = (key, val);
		tmp =  format % values;
		jsonstr = jsonstr + tmp;
	jsonstr = jsonstr +  "}";
	return jsonstr;
	

#根据规定格式的数组字符串生成json字符串
def ArrayObjToJson(arrstr):
	liststr = arrstr[1:len(arrstr) -1];
	objliststr = liststr.split(',');
	retstr = "[";
	j = 0;
	for i in range(0, len(objliststr)):
		if j > 0:
			retstr = retstr + ",";
		j = j + 1;
		tmp = ObjStrToJsonStr(objliststr[i]);
		retstr = retstr + tmp;
	retstr = retstr + "]";
	return retstr;

######################################################################
print "========================生成结果======================================"

listobj = "[{name:s=alise;age:n=456;sex:s=1},{name:s=alise;age:n=456;sex:s=1}]";

listjson = ArrayObjToJson(listobj);
#print listjson;

#解析excel文件
def ParseExcelConfigFile(filename):
	filelist = filename.split('.');
	txtfile = "configfile//" + filelist[0] + ".txt";
	configfile = open(txtfile, "w+");
	configfile.write("[\n");
	book = xlrd.open_workbook(filename);
	book_sheet = book.sheet_by_index(0);
	print "================[ParseExcelConfigFile]========================="
	print "filename:", filename;
	print "%nrow,%ncolumn" % (book_sheet.nrows, book_sheet.ncols);
	for i in range(3, book_sheet.nrows):
		colindex = 0;
		configfile.write("{");
		for j in range(0, book_sheet.ncols):
			if (colindex > 0):
				configfile.write(",");
			colindex = colindex + 1;
			var = book_sheet.cell_value(rowx = i, colx =j)
			#字段类型
			fieldtype = book_sheet.cell_value(rowx = 1, colx = j);
			key = "\"" + str(book_sheet.cell_value(rowx = 2, colx =j)) + "\"";
			configfile.write(key);
			configfile.write(":");
			if (fieldtype == "number"):
				tmpnum = int(var);
				configfile.write(str(int(var)));
			elif (fieldtype == "object"):
				tmpstr = ObjStrToJsonStr(str(var));
				configfile.write(tmpstr);
			elif (fieldtype == "string"):
				tmpstr = "\"" + str(var) + "\"";
				configfile.write(tmpstr);
			elif (fieldtype == "array:object"):
				tmpstr = ArrayObjToJson(str(var));
				configfile.write(tmpstr);
		configfile.write("}");
		if (i < (book_sheet.nrows - 1)):
			configfile.write(",");
			
		configfile.write("\n");	
	configfile.write("]");
	configfile.close();
	print "文件 %s 生成完毕" % txtfile

#===========================================================

#读取生成列表
def GenerateConfigfile():
	files = open("filelist.txt");
	filelist = files.readlines();
	for i in range(0, len(filelist)):
		#print "filename:%s" % filelist[i];
		#生成配置文件
		if (len(filelist[i]) > 1):
			filename = filelist[i];
			if (filename[len(filename) -1] == '\n'):
				filename=filename[0:len(filename) -1];
			ParseExcelConfigFile(filename);
GenerateConfigfile();





