#pragma once
#include <string>
#include <vector>
#include <map>
#include "cocos2d.h"

#include "json/document.h"
#include "json/rapidjson.h"
using namespace std;
USING_NS_CC;
using namespace rapidjson;
//后续具体的数据从这个类派生下去，再进行扩展。
struct SDataBase{
	SDataBase(){
		nID = 0;
	}
	virtual ~SDataBase(){}

	int nID;
};

class CDataBaseMgr{
public:
	CDataBaseMgr();
	virtual ~CDataBaseMgr();
	virtual void loadFile(const string& strPath);

	//纯虚函数
	virtual void parse(Document& doc) = 0;
	SDataBase* getDataByID(const int& nID);
	int getSize();
	SDataBase* getDataByIndex(int nIndex);
	vector<SDataBase*>& getAllData();
protected:
	vector<SDataBase*> m_vecDatas;
};