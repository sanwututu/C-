#include "ConfigMgr.h"

CConfigMgr* CConfigMgr::m_spInstance = nullptr;
CConfigMgr::CConfigMgr(){

}
CConfigMgr::~CConfigMgr(){

}
CDataBaseMgr* CConfigMgr::getData(string strName){
	if (strName.empty()){
		return nullptr;
	}
	//
	map<string, CDataBaseMgr*>::iterator iter = m_mapDatas.find(strName);
	return iter->second;
}

void CConfigMgr::setData(string strName, CDataBaseMgr* pDataBaseMgr){
	if (strName.empty() || !pDataBaseMgr){
		return;
	}
	m_mapDatas.insert(pair<string, CDataBaseMgr*>(strName, pDataBaseMgr));
}
CConfigMgr* CConfigMgr::getInstance()
{
	if (!m_spInstance)
	{
		m_spInstance = new CConfigMgr();
	}
	return m_spInstance;
}