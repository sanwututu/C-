#pragma once

struct SLevelDt
{
	SLevelDt(){
		nID = 0;
		nRowSize = 0;
		nColSize = 0;
		nBirthRow = 0;
		nBirthCol = 0;
	}
	~SLevelDt(){
		for (int i = 0; i < nRowSize; i++)
		{
			//数组指针到删除用delete [] + 数组名称
			delete[] pArrMap[i];
		}
		delete[] pArrMap;
	}
	string strName;
	int nID;
	int nRowSize;
	int nColSize;
	int nBirthRow;
	int nBirthCol;
	int** pArrMap;
	/*int arrMap[50][50];*/
};

class CLevelDtMgr
{
public:
	CLevelDtMgr();
	~CLevelDtMgr();

	void loadFile(const string& strPath);
	SLevelDt* getDataByID(int nID);
	int getSize();
	SLevelDt* getDataByIndex(int nIndex);
	vector<SLevelDt*> m_VecData;
};
struct SBulletDt
{
	SBulletDt(){
		nID = 0;
		nSpeed = 0;
		nAck = 0;
	}
	int nID;
	int nSpeed;
	int nAck;
	string strName;
	string strPic;
};
class CBulletDtMgr
{
public:
	CBulletDtMgr();
	~CBulletDtMgr();
	void loadFile(const string& strPath);
	SBulletDt* getDataByID(int nID);
	int getSize();
	SBulletDt* getDataByIndex(int nIndex);
	vector<SBulletDt*> m_VecData;
};
struct SEnemyDt
{
	SEnemyDt(){
		nID = 0;
		nSpeed = 0;
		nHp = 0;
		nAck = 0;
	}
	int nID;
	int nSpeed;
	int nHp;
	int nAck;
	string strName;
	string strPic;
};
class CEnemyDtMgr
{
public:
	CEnemyDtMgr();
	~CEnemyDtMgr();
	void loadFile(const string& strPath);
	SEnemyDt* getDataByID(int nID);
	int getSize();
	SEnemyDt* getDataByIndex(int nIndex);
	vector<SEnemyDt*> m_VecData;
};
struct SPlayerDt{
	SPlayerDt(){
		nID = 0;
		nHp = 0;
		nAck = 0;
	}
	int nID;
	int nHp;
	int nBulletID;
	int nAck;
	string strName;
	string strPic;
};
class CPlayerDtMgr
{
public:
	CPlayerDtMgr();
	~CPlayerDtMgr();
	void loadFile(const string& strPath);
	SPlayerDt* getDataByID(int nID);
	int getSize();
	SPlayerDt* getDataByIndex(int nIndex);
	vector<SPlayerDt*> m_VecData;
};