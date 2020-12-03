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
	//ע��map����������������ŵķ��ʷ�ʽ����һ��������û�ж�Ӧ�ļ���ֵ������ ���� name   m_mapDatas["name"] ����map����û��name�������Ӧ��ֵ��  ���ʱ������������һ��name���ԣ���Ӧֵ��nullptr
	map<string, CDataBaseMgr*>::iterator iter = m_mapDatas.find(strName);
	return iter->second;
}

void CConfigMgr::setData(string strName, CDataBaseMgr* pDataBaseMgr)
{
	if (strName.empty()||!pDataBaseMgr)
	{
		return;
	}
	//name:"����"
	//�����ţ� map["name"] = "����";  ���ʱ��map�����name�� ���滻Ϊ����
	//������ظ��洢�����滻��
	//m_mapDatas[strName] = pDataBaseMgr;
	//insert���ظ�key�ǲ������� map.insert(name,���ģ�   ִ����֮�� map��name��Ӧ��������
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
