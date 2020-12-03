#pragma once
#include "DataBase.h"
//�����κξ�����������ڴ�ȡ���ݡ�
//���ڹ������еľ������ݹ����ߣ��ø�ָ����д���ֻ��Ҫ����һ��ָ�롣
//ֻ��һ��ָ�����ͣ�������֣�ͨ�����֣�map�������Ѿ������ݹ����ߵ����ָ���ָ��󶨡�
class CConfigMgr
{
public:
	static CConfigMgr* getInstance();
	void init(function<void()> loadFunc);
	//�����ȡ�����ӿ�
	CDataBaseMgr* getData(string strName);
	void setData(string strName, CDataBaseMgr* pDataBaseMgr);
private:
	CConfigMgr();
	~CConfigMgr();
	static CConfigMgr* m_spInstance;
	map<string, CDataBaseMgr*> m_mapDatas;
};

