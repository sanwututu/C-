#pragma once

struct Vec2{
	int nRow;
	int nCol;
	int nRowBk;
	int nColBk;
};

struct SLevelDt
{
	SLevelDt(){
		nID = 0;
		nRowSize = 0;
		nColSize = 0;
		nBirthRow = 0;
		nBirthCol = 0;
		memset(arrMap, 0, sizeof(arrMap));
	}
	string strName;
	int nID;
	int nRowSize;
	int nColSize;
	int nBirthRow;
	int nBirthCol;
	int arrMap[50][50];
};

struct SLevelDtMgr
{
	void loadFile(const string& strPath);
	SLevelDt getDataByID(int nID);
	int getSize();
	SLevelDt getDataByIndex(int nIndex);
	vector<SLevelDt> VecData;
};

struct SBulletDt
{
	SBulletDt(){
		nID = 0;
		nSpeed = 0;
	}
	int nID;
	int nSpeed;
	string strName;
	string strPic;
};

struct SBulletDtMgr
{
	void loadFile(const string& strPath);
	SBulletDt getDataByID(int nID);
	int getSize();
	SBulletDt getDataByIndex(int nIndex);
	vector<SBulletDt> VecData;
};

struct SEnemyDt
{
	SEnemyDt(){
		nID = 0;
		nHp = 0;
		nAck = 0;
		nSpeed = 0;
		nAckSpeed = 0;
		nBulletID = 0;
	}
	int nID;
	int nHp;
	int nAck;
	int nSpeed;
	int nAckSpeed;
	int nBulletID;
	string strName;
	string strPic;
};

struct SEnemyDtMgr
{
	void loadFile(const string& strPath);
	SEnemyDt getDataByID(int nID);
	int getSize();
	SEnemyDt getDataByIndex(int nIndex);
	vector<SEnemyDt> VecData;
};

struct SRoleDt
{
	SRoleDt(){
		nID = 0;
		nHp = 0;
		nAck = 0;
		nBulletID = 0;
	}
	int nID;
	int nHp;
	int nAck;
	int nBulletID;
	string strName;
	string strPic;
};

struct SRoleDtMgr
{
	void loadFile(const string& strPath);
	SRoleDt getDataByID(int nID);
	int getSize();
	SRoleDt getDataByIndex(int nIndex);
	vector<SRoleDt> VecData;
};
