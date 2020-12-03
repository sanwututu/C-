#include "ConfigMgr.h"

CConfigMgr* CConfigMgr::m_spInstance = nullptr;
CConfigMgr::CConfigMgr()
{
}


CConfigMgr::~CConfigMgr()
{
}

CDataBaseMgr* CConfigMgr::getData(string strName)
{
	if (strName.empty())
	{
		return nullptr;
	}
	//return m_mapDatas[strName];
	//注意map容器，如果是中括号的访问方式，万一容器里面没有对应的键和值，比如 访问 name   m_mapDatas["name"] 但是map里面没有name这个键对应的值。  这个时候会往里面插入一个name属性，对应值是nullptr
	map<string, CDataBaseMgr*>::iterator iter = m_mapDatas.find(strName);
	return iter->second;
}

void CConfigMgr::setData(string strName, CDataBaseMgr* pDataBaseMgr)
{
	if (strName.empty()||!pDataBaseMgr)
	{
		return;
	}
	//name:"张三"
	//中括号： map["name"] = "李四";  这个时候map里面的name会 被替换为李四
	//如果有重复存储，会替换。
	//m_mapDatas[strName] = pDataBaseMgr;
	//insert有重复key是不操作。 map.insert(name,李四）   执行完之后 map的name对应还是张三
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

void CConfigMgr::init(function<void()> loadFunc)
{
	loadFunc();
}
