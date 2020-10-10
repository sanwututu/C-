#pragma once

struct SLevelDt
{
	~SLevelDt(){
		for (int i = 0; i < nRowSize; i++)
		{
			//����ָ�뵽ɾ����delete [] + ��������
			delete[] pArrMap[i];
		}
		delete[] pArrMap;
	}
	int nID;
	int nRowSize;
	int nColSize;
	int nBirthRow;
	int nBirthCol;
	string strName;
	int** pArrMap;
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
//��ɫ
struct SRoleDt
{
	int nID;
	int nHp;
	int nMp;
	int nAck;
	int nDef;
	string strName;
	string strPic;
};

class CRoleDtMgr
{
public:
	CRoleDtMgr();
	~CRoleDtMgr();

	void loadFile(const string& strPath);
	SRoleDt* getDataByID(int nID);
	int getSize();
	SRoleDt* getDataByIndex(int nIndex);
	vector<SRoleDt*>& getAllData();
private:
	vector<SRoleDt*> m_VecData;
};
//Npc
struct SNpcDt
{
	int nID;
	int nRow;
	int nCol;
	int nMapID;
	int nType;
	string strName;
	string strPic;
};

class CNpcDtMgr
{
public:
	CNpcDtMgr();
	~CNpcDtMgr();

	void loadFile(const string& strPath);
	SNpcDt* getDataByID(int nID);
	int getSize();
	SNpcDt* getDataByIndex(int nIndex);
	vector<SNpcDt*>& getAllData();
private:
	vector<SNpcDt*> m_VecData;
};
//��Ʒ
struct SGoodsDt
{
	int nID;
	int nNpcID;
	int nHp;
	int nMp;
	int nAck;
	int nDef;
	int nNum;
	int nPrice;
	int nType;
	string strName;
	string strPic;
	
	
};

class CGoodsDtMgr
{
public:
	CGoodsDtMgr();
	~CGoodsDtMgr();

	void loadFile(const string& strPath);
	SGoodsDt* getDataByID(int nID);
	int getSize();
	SGoodsDt* getDataByIndex(int nIndex);
	vector<SGoodsDt*> getDataByGoodsID(int nNpcID);
private:
	vector<SGoodsDt*> m_VecData;
};
//��������
struct SMonsterDt
{
	int nID;
	int nAck;
	int nHp;
	int nMapID;
	string strName;
	string strPic;
};

class CMonsterDtMgr
{
public:
	CMonsterDtMgr();
	~CMonsterDtMgr();

	void loadFile(const string& strPath);
	SMonsterDt* getDataByID(int nID);
	int getSize();
	SMonsterDt* getDataByIndex(int nIndex);
	vector<SMonsterDt*> getDataByMonsterID(int nMonsterID);
private:
	vector<SMonsterDt*> m_VecData;
};
//����
struct STaskDt
{
	int nID;
	int nNpcID;
	int nType;
	int nStates;
	string strName;
	string strDetail;


};

class CTaskDtMgr
{
public:
	CTaskDtMgr();
	~CTaskDtMgr();
	void changeState(int nID);
	void loadFile(const string& strPath);
	STaskDt* getDataByID(int nID);
	int getSize();
	STaskDt* getDataByIndex(int nIndex);
	vector<STaskDt*> getDataByTaskID(int nNpcID);
private:
	vector<STaskDt*> m_VecData;
};