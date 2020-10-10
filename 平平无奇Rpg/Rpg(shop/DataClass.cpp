#include "stdafx.h"
#include "DataClass.h"


CLevelDtMgr::CLevelDtMgr()
{
}

CLevelDtMgr::~CLevelDtMgr()
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		SAFE_DEL(m_VecData[i]);
	}
	m_VecData.clear();
}

void CLevelDtMgr::loadFile(const string& strPath)
{
	ifstream infile(strPath);
	if (infile)
	{
		int nCount = 0;
		infile >> nCount;
		for (int i = 0; i < nCount; i++)
		{
			SLevelDt* pData = new SLevelDt();
			infile >> pData->strName >> pData->nID >> pData->nRowSize 
				>> pData->nColSize >> pData->nBirthRow >> pData->nBirthCol;
			//动态创建二维数组
			pData->pArrMap = new int*[pData->nRowSize];
			for (int m = 0; m < pData->nRowSize; m++)
			{
				pData->pArrMap[m] = new int[pData->nColSize];
			}

			for (int m = 0; m < pData->nRowSize; m++)
			{
				for (int n = 0; n < pData->nColSize; n++)
				{
					infile >> pData->pArrMap[m][n];
				}
			}
			m_VecData.push_back(pData);
		}
	}
	infile.close();
}

SLevelDt* CLevelDtMgr::getDataByID(int nID)
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		if (m_VecData[i]->nID == nID)
		{
			return m_VecData[i];
		}
	}
	return nullptr;
}

int CLevelDtMgr::getSize()
{
	return m_VecData.size();
}

SLevelDt* CLevelDtMgr::getDataByIndex(int nIndex)
{
	if (nIndex < 0 || nIndex > m_VecData.size() - 1)
	{
		return nullptr;
	}
	return m_VecData[nIndex];
}
//角色数据
CRoleDtMgr::CRoleDtMgr()
{

}

CRoleDtMgr::~CRoleDtMgr()
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		SAFE_DEL(m_VecData[i]);
	}
	m_VecData.clear();
}

void CRoleDtMgr::loadFile(const string& strPath)
{
	ifstream infile(strPath);
	if (infile)
	{
		int nCount = 0;
		string str;
		getline(infile, str);
		infile >> nCount;
		for (int i = 0; i < nCount; i++)
		{
			SRoleDt* pData = new SRoleDt();
			infile >> pData->nID >> pData->nHp >> pData->nMp >> pData->nAck >> pData->nDef >> pData->strName >> pData->strPic;
			m_VecData.push_back(pData);
		}
	}
	infile.close();
}

SRoleDt* CRoleDtMgr::getDataByID(int nID)
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		if (m_VecData[i]->nID == nID)
		{
			return m_VecData[i];
		}
	}
	return nullptr;
}

int CRoleDtMgr::getSize()
{
	return m_VecData.size();
}

SRoleDt* CRoleDtMgr::getDataByIndex(int nIndex)
{
	if (nIndex < 0 || nIndex > m_VecData.size() - 1)
	{
		return nullptr;
	}
	return m_VecData[nIndex];
}

vector<SRoleDt*>& CRoleDtMgr::getAllData()
{
	return m_VecData;
}
//Npc数据
CNpcDtMgr::CNpcDtMgr()
{

}

CNpcDtMgr::~CNpcDtMgr()
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		SAFE_DEL(m_VecData[i]);
	}
	m_VecData.clear();
}
void CNpcDtMgr::loadFile(const string& strPath)
{
	ifstream infile(strPath);
	if (infile)
	{
		int nCount = 0;
		string str;
		getline(infile, str);
		infile >> nCount;
		for (int i = 0; i < nCount; i++)
		{
			SNpcDt* pData = new SNpcDt();
			infile >> pData->nID >> pData->nMapID >> pData->nRow  >> pData->nCol>> pData->strName >> pData->strPic>>pData->nType;
			m_VecData.push_back(pData);
		}
	}
	infile.close();
}

SNpcDt* CNpcDtMgr::getDataByID(int nID)
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		if (m_VecData[i]->nID == nID)
		{
			return m_VecData[i];
		}
	}
	return nullptr;
}

int CNpcDtMgr::getSize()
{
	return m_VecData.size();
}

SNpcDt* CNpcDtMgr::getDataByIndex(int nIndex)
{
	if (nIndex < 0 || nIndex > m_VecData.size() - 1)
	{
		return nullptr;
	}
	return m_VecData[nIndex];
}

vector<SNpcDt*>& CNpcDtMgr::getAllData()
{
	return m_VecData;
}
//货物数据
CGoodsDtMgr::CGoodsDtMgr()
{

}

CGoodsDtMgr::~CGoodsDtMgr()
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		SAFE_DEL(m_VecData[i]);
	}
	m_VecData.clear();
}
void CGoodsDtMgr::loadFile(const string& strPath)
{
	ifstream infile(strPath);
	if (infile)
	{
		int nCount = 0;
		string str;
		getline(infile, str);
		infile >> nCount;
		for (int i = 0; i < nCount; i++)
		{
			SGoodsDt* pData = new SGoodsDt();
			pData->nNum = 1;
			infile >> pData->nID >> pData->nNpcID >> pData->strName >>pData->strPic>> pData->nHp
				>> pData->nMp >> pData->nAck >> pData->nDef >> pData->nPrice>>pData->nType;
			m_VecData.push_back(pData);
		}
	}
	infile.close();
}

SGoodsDt* CGoodsDtMgr::getDataByID(int nID)
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		if (m_VecData[i]->nID == nID)
		{
			return m_VecData[i];
		}
	}
	return nullptr;
}

int CGoodsDtMgr::getSize()
{
	return m_VecData.size();
}

SGoodsDt* CGoodsDtMgr::getDataByIndex(int nIndex)
{
	if (nIndex < 0 || nIndex > m_VecData.size() - 1)
	{
		return nullptr;
	}
	return m_VecData[nIndex];
}

vector<SGoodsDt*> CGoodsDtMgr::getDataByGoodsID(int nNpcID)
{
	vector<SGoodsDt*> VecData;
	for (SGoodsDt* pData : m_VecData)
	{
		if (pData->nNpcID == nNpcID)
		{
			VecData.push_back(pData);
		}
	}
	return VecData;
}
//怪物数据
CMonsterDtMgr::CMonsterDtMgr()
{

}

CMonsterDtMgr::~CMonsterDtMgr()
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		SAFE_DEL(m_VecData[i]);
	}
	m_VecData.clear();
}
void CMonsterDtMgr::loadFile(const string& strPath)
{
	ifstream infile(strPath);
	if (infile)
	{
		int nCount = 0;
		string str;
		getline(infile, str);
		infile >> nCount;
		for (int i = 0; i < nCount; i++)
		{
			SMonsterDt* pData = new SMonsterDt();
			infile >> pData->nID >> pData->nMapID >> pData->nAck >> pData->nHp >> pData->strName >> pData->strPic;
			m_VecData.push_back(pData);
		}
	}
	infile.close();
}

SMonsterDt* CMonsterDtMgr::getDataByID(int nID)
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		if (m_VecData[i]->nID == nID)
		{
			return m_VecData[i];
		}
	}
	return nullptr;
}

int CMonsterDtMgr::getSize()
{
	return m_VecData.size();
}

SMonsterDt* CMonsterDtMgr::getDataByIndex(int nIndex)
{
	if (nIndex < 0 || nIndex > m_VecData.size() - 1)
	{
		return nullptr;
	}
	return m_VecData[nIndex];
}

vector<SMonsterDt*> CMonsterDtMgr::getDataByMonsterID(int nMonsterID)
{
	vector<SMonsterDt*> VecData;
	for (SMonsterDt* pData : m_VecData)
	{
		if (pData->nID == nMonsterID)
		{
			VecData.push_back(pData);
		}
	}
	return VecData;
}
//任务
CTaskDtMgr::CTaskDtMgr()
{
	
}

CTaskDtMgr::~CTaskDtMgr()
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		SAFE_DEL(m_VecData[i]);
	}
	m_VecData.clear();
}
void CTaskDtMgr::changeState(int nID)
{
	for (int i = 0; i < m_VecData.size(); i++){
		if (m_VecData[i]->nID == nID){
			m_VecData[i]->nStates = 1;
		}
	}

}
void CTaskDtMgr::loadFile(const string& strPath)
{
	ifstream infile(strPath);
	if (infile)
	{
		int nCount = 0;
		string str;
		getline(infile, str);
		infile >> nCount;
		for (int i = 0; i < nCount; i++)
		{
			STaskDt* pData = new STaskDt();
			infile >> pData->nID >> pData->nNpcID >> pData->strName >> pData->strDetail;
			pData->nStates = 0;
			m_VecData.push_back(pData);
		}
	}
	infile.close();
}

STaskDt* CTaskDtMgr::getDataByID(int nID)
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		if (m_VecData[i]->nID == nID)
		{
			return m_VecData[i];
		}
	}
	return nullptr;
}

int CTaskDtMgr::getSize()
{
	return m_VecData.size();
}

STaskDt* CTaskDtMgr::getDataByIndex(int nIndex)
{
	if (nIndex < 0 || nIndex > m_VecData.size() - 1)
	{
		return nullptr;
	}
	return m_VecData[nIndex];
}

vector<STaskDt*> CTaskDtMgr::getDataByTaskID(int nNpcID)
{
	vector<STaskDt*> VecData;
	for (STaskDt* pData : m_VecData)
	{
		if (pData->nNpcID == nNpcID)
		{
			VecData.push_back(pData);
		}
	}
	return VecData;
}