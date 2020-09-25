#include "stdafx.h"
#include "DataStruct.h"

void SLevelDtMgr::loadFile(const string& strPath)
{
	ifstream infile(strPath);
	if (infile)
	{
		int nCount = 0;
		infile >> nCount;
		for (int i = 0; i < 3; i++)
		{
			SLevelDt levelDt;
			infile >> levelDt.strName >> levelDt.nID >> levelDt.nRowSize >> levelDt.nColSize >> levelDt.nBirthRow >> levelDt.nBirthCol;
			for (int m = 0; m < levelDt.nRowSize; m++)
			{
				for (int n = 0; n < levelDt.nColSize; n++)
				{
					infile >> levelDt.arrMap[m][n];
				}
			}
			VecData.push_back(levelDt);
		}
	}
	infile.close();
}

SLevelDt SLevelDtMgr::getDataByID(int nID)
{
	for (SLevelDt data : VecData)
	{
		if (data.nID == nID)
		{
			return data;
		}
	}
	SLevelDt levelDt;
	return levelDt;
}

int SLevelDtMgr::getSize()
{
	return VecData.size();
}

SLevelDt SLevelDtMgr::getDataByIndex(int nIndex)
{
	if (nIndex < 0 || nIndex > VecData.size() - 1)
	{
		SLevelDt data;
		return data;
	}
	return VecData[nIndex];
}

void SBulletDtMgr::loadFile(const string& strPath)
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
			SBulletDt data;
			infile >> data.nID >> data.nSpeed >> data.strName >> data.strPic>>data.nAck;
			VecData.push_back(data);
		}
	}
	infile.close();
}

SBulletDt SBulletDtMgr::getDataByID(int nID)
{
	for (SBulletDt data : VecData)
	{
		if (data.nID == nID)
		{
			return data;
		}
	}
	SBulletDt data;
	return data;
}

int SBulletDtMgr::getSize()
{
	return VecData.size();
}

SBulletDt SBulletDtMgr::getDataByIndex(int nIndex)
{
	if (nIndex < 0 || nIndex > VecData.size() - 1)
	{
		SBulletDt data;
		return data;
	}
	return VecData[nIndex];
}
//敌人SEnemyDt
void SEnemyDtMgr::loadFile(const string& strPath)
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
			SEnemyDt data;
			infile >> data.nID >> data.nSpeed >> data.strName >> data.strPic >> data.nAck >> data.nHp;
			VecData.push_back(data);
		}
	}
	infile.close();
}

SEnemyDt SEnemyDtMgr::getDataByID(int nID)
{
	for (SEnemyDt data : VecData)
	{
		if (data.nID == nID)
		{
			return data;
		}
	}
	SEnemyDt data;
	return data;
}

int SEnemyDtMgr::getSize()
{
	return VecData.size();
}

SEnemyDt SEnemyDtMgr::getDataByIndex(int nIndex)
{
	if (nIndex < 0 || nIndex > VecData.size() - 1)
	{
		SEnemyDt data;
		return data;
	}
	return VecData[nIndex];
}
//玩家数据
//敌人SEnemyDt
void SPlayerDtMgr::loadFile(const string& strPath)
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
			SPlayerDt data;
			infile >> data.nID >>data.strName>>data.nBulletID >> data.strPic>>data.nHp>>data.nAck;
			VecData.push_back(data);
		}
	}
	infile.close();
}

SPlayerDt SPlayerDtMgr::getDataByID(int nID)
{
	for (SPlayerDt data : VecData)
	{
		if (data.nID == nID)
		{
			return data;
		}
	}
	SPlayerDt data;
	return data;
}

int SPlayerDtMgr::getSize()
{
	return VecData.size();
}

SPlayerDt SPlayerDtMgr::getDataByIndex(int nIndex)
{
	if (nIndex < 0 || nIndex > VecData.size() - 1)
	{
		SPlayerDt data;
		return data;
	}
	return VecData[nIndex];
}
