#pragma once
#include "DataBase.h"
//不做任何具体操作，用于存取数据。
//用于管理所有的具体数据管理者，用父指针进行处理，只需要管理一种指针。
//只有一种指针类型，如何区分，通过名字，map容器，把具体数据管理者的名字跟父指针绑定。
class CConfigMgr
{
public:
	static CConfigMgr* getInstance();
	void init(function<void()> loadFunc);
	//定义存取两个接口
	CDataBaseMgr* getData(string strName);
	void setData(string strName, CDataBaseMgr* pDataBaseMgr);
private:
	CConfigMgr();
	~CConfigMgr();
	static CConfigMgr* m_spInstance;
	map<string, CDataBaseMgr*> m_mapDatas;
};

