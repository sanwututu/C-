#include "stdafx.h"
#include "DataStruct.h"

CLevelDtMgr::CLevelDtMgr()
{
}
CLevelDtMgr::~CLevelDtMgr()
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		if (m_VecData[i])
		{
			delete m_VecData[i];
			m_VecData[i] = nullptr;
		}
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
			SLevelDt*pData = new SLevelDt();
			infile >> pData->strName >> pData->nID >> pData->nRowSize >> pData->nColSize >> pData->nBirthRow >> pData->nBirthCol;
			//
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
//子弹
CBulletDtMgr::CBulletDtMgr()
{
}
CBulletDtMgr::~CBulletDtMgr()
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		if (m_VecData[i])
		{
			delete m_VecData[i];
			m_VecData[i] = nullptr;
		}
	}
	m_VecData.clear();
}
void CBulletDtMgr::loadFile(const string& strPath)
{
	ifstream infile(strPath);
	if (infile)
	{
		string str;
		getline(infile, str);
		int nCount = 0;
		infile >> nCount;
		for (int i = 0; i < nCount; i++)
		{
			SBulletDt* pData = new SBulletDt;
			infile >> pData->nID >> pData->nSpeed >> pData->strName >> pData->strPic >> pData->nAck;
			m_VecData.push_back(pData);
		}
	}
	infile.close();
}

SBulletDt* CBulletDtMgr::getDataByID(int nID)
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

int CBulletDtMgr::getSize()
{
	return m_VecData.size();
}

SBulletDt* CBulletDtMgr::getDataByIndex(int nIndex)
{
	if (nIndex < 0 || nIndex > m_VecData.size() - 1)
	{
		SBulletDt* pData = new SBulletDt();
		return pData;
	}
	return m_VecData[nIndex];
}
//敌人SEnemyDt
CEnemyDtMgr::CEnemyDtMgr()
{
}
CEnemyDtMgr::~CEnemyDtMgr()
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		if (m_VecData[i])
		{
			delete m_VecData[i];
			m_VecData[i] = nullptr;
		}
	}
	m_VecData.clear();
}
void CEnemyDtMgr::loadFile(const string& strPath)
{
	ifstream infile(strPath);
	if (infile)
	{
		string str;
		getline(infile, str);
		int nCount = 0;
		infile >> nCount;
		for (int i = 0; i < nCount; i++)
		{
			SEnemyDt* pData = new SEnemyDt();
			infile >> pData->nID >> pData->nSpeed >> pData->strName >> pData->strPic >> pData->nAck >> pData->nHp;
			m_VecData.push_back(pData);
		}
	}
	infile.close();
}

SEnemyDt* CEnemyDtMgr::getDataByID(int nID)
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

int CEnemyDtMgr::getSize()
{
	return m_VecData.size();
}

SEnemyDt* CEnemyDtMgr::getDataByIndex(int nIndex)
{
	if (nIndex < 0 || nIndex > m_VecData.size() - 1)
	{
		SEnemyDt* pData = new SEnemyDt();
		return pData;
	}
	return m_VecData[nIndex];
}
//玩家数据
CPlayerDtMgr::CPlayerDtMgr()
{
}
CPlayerDtMgr::~CPlayerDtMgr()
{
	for (int i = 0; i < m_VecData.size(); i++)
	{
		if (m_VecData[i])
		{
			delete m_VecData[i];
			m_VecData[i] = nullptr;
		}
	}
	m_VecData.clear();
}
void CPlayerDtMgr::loadFile(const string& strPath)
{
	ifstream infile(strPath);
	if (infile)
	{
		string str;
		getline(infile, str);
		int nCount = 0;
		infile >> nCount;
		for (int i = 0; i < nCount; i++)
		{

			SPlayerDt* pData = new SPlayerDt();
			infile >> pData->nID >> pData->strName >> pData->nBulletID >> pData->strPic >> pData->nHp >> pData->nAck;
			m_VecData.push_back(pData);
		}
	}
	infile.close();
}

SPlayerDt* CPlayerDtMgr::getDataByID(int nID)
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

int CPlayerDtMgr::getSize()
{
	return m_VecData.size();
}

SPlayerDt* CPlayerDtMgr::getDataByIndex(int nIndex)
{
	if (nIndex < 0 || nIndex > m_VecData.size() - 1)
	{
		SPlayerDt* pData = new SPlayerDt();
		return pData;
	}
	return m_VecData[nIndex];
}
