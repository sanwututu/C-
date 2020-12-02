#pragma once
#include "DataBase.h"

class CConfigMgr{
public:
	static CConfigMgr* getInstance();
	//
	CDataBaseMgr* getData(string strName);
	void setData(string strName, CDataBaseMgr* pDataBaseMgr);
private:
	CConfigMgr();
	~CConfigMgr();
	static CConfigMgr* m_spInstance;
	map<string, CDataBaseMgr*>m_mapDatas;

};