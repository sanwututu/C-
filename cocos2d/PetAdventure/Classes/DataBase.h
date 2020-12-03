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
struct SDataBase
{
	SDataBase()
	{
		nID = 0;
	}
	virtual ~SDataBase(){}
	
	int nID;
};

//虚析构函数
//当基类指针指向子类对象时，如果基类到析构函数不是virsual，释放该基类指针时会导致子类到析构函数没有被调用，从而可能导致内存泄漏

//后续具体的数据管理者从这个类派生下去，再进行扩展。
class CDataBaseMgr
{
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
