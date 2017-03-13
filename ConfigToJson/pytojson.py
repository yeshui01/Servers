#encoding=utf-8
import os;
import sys;
import string;
import xlrd;

#�ָ��ַ����������ֶ��б�
def SplitObjStrField(objstr):
	"�ָ��ַ����������ֶ�ӳ���"
	fieldlist = objstr.split(';');
	return fieldlist;

#�����ֶ��б������ֵ�ӳ���
def ConstructFieldDictFromFiledList(fieldlist):
	fielddict = {}
	for i in range(0, len(fieldlist)):
		fieldstr = fieldlist[i].split(':');
		fielddict[fieldstr[0]] = fieldstr[1];
	return fielddict;
	
def GetJsonObjStr(configstr):
	'''���ݹ涨��ʽ�Ķ��������ַ�����
	����json��ʽ���ַ���'''
	configstr = configstr[1:len(configstr)-1];
	fieldlist = SplitObjStrField(configstr);
	fielddict = ConstructFieldDictFromFiledList(fieldlist);
	#�����ֶ��ֵ������json����
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
	
	
#���ݹ涨��ʽ���ַ��������ض�Ӧ��ֵ
def GetValueFromStr(formatstr):
	substr = formatstr.split('=');
	#ֵ����-ֵ
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
#���ַ�������һ��json�����ַ�������
#########################################
def ObjStrToJsonStr(configstr):
	'''���ݹ涨��ʽ�Ķ��������ַ�����
	����json��ʽ���ַ���'''
	configstr = configstr[1:len(configstr)-1];
	fieldlist = SplitObjStrField(configstr);
	fielddict = ConstructFieldDictFromFiledList(fieldlist);
	#�����ֶ��ֵ������json����
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
	

#���ݹ涨��ʽ�������ַ�������json�ַ���
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
print "========================���ɽ��======================================"

listobj = "[{name:s=alise;age:n=456;sex:s=1},{name:s=alise;age:n=456;sex:s=1}]";

listjson = ArrayObjToJson(listobj);
#print listjson;

#����excel�ļ�
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
			#�ֶ�����
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
	print "�ļ� %s �������" % txtfile

#===========================================================

#��ȡ�����б�
def GenerateConfigfile():
	files = open("filelist.txt");
	filelist = files.readlines();
	for i in range(0, len(filelist)):
		#print "filename:%s" % filelist[i];
		#���������ļ�
		if (len(filelist[i]) > 1):
			filename = filelist[i];
			if (filename[len(filename) -1] == '\n'):
				filename=filename[0:len(filename) -1];
			ParseExcelConfigFile(filename);
GenerateConfigfile();





