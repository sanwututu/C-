#pragma once
#include "DataClass.h"

//struct SItem{
//	SItem(){
//		nID = 0;
//		nNpcID = 0;
//		nHp = 0;
//		nMp = 0;
//		nAck = 0;
//		nDef = 0;
//		nNum = 1;
//		nState = 0;
//		nType = 0;
//	};
//	int nID;
//	int nNpcID;
//	int nHp;
//	int nMp;
//	int nAck;
//	int nDef;
//	int nNum;
//	int nType;
//	int nState;
//	int nPrice;
//	string strName;
//	string strPic;
//
//	
//};
struct SPet{
	SPet(){
		nID = 0 ;
		nRow = 0 ;
		nCol = 0;
		nHp = 0;
		nMp = 0;
		nAck = 0;
		nDef = 0;
	};
	int nID;
	int nRow;
	int nCol;
	int nHp;
	int nMp;
	int nAck;
	int nDef;
	string strName;
	string strPic;
};
class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	//初始化配置表数据
	void initConfig(SRoleDt* pConfig);
	void backup();
	void revert();
	void update();
	void render();
	/*SPet* getPet(int nInRow, int nInCol);*/
	SPet* gainPet();
	void setPet(SGoodsDt* pData);
	void addItem(SGoodsDt* pData);
	void equip(SGoodsDt* pData);
	void removeItem(SGoodsDt* pData);
	void addTask(STaskDt* pData);
	void setPosition(int nInRow, int nInCol);
	vector<STaskDt*>& getAllVecTask();
	vector<SGoodsDt*>& getAllVecItem();
	SGoodsDt* getAllEquip(int Index);
	SYN_THE_SIZE(int, m_nMoney, Money);
	SYN_THE_SIZE(int, m_nRow, Row);
	SYN_THE_SIZE(int, m_nCol, Col);
	SYN_THE_SIZE(int, m_nDef, Def);
	SYN_THE_SIZE(string, m_strName, Name);
	SYN_THE_SIZE(string, m_strPic, Pic);
	SYN_THE_SIZE(int, m_nHp, Hp);
	SYN_THE_SIZE(int, m_nMp, Mp);
	SYN_THE_SIZE(int, m_nAck, Ack);
	SYN_THE_SIZE(int, m_nID, ID);

private:
	int nPetExit;
	int m_nRowBk;
	int m_nColBk;
	SPet* m_nPet;
	SGoodsDt* m_arrEquip[EQUIP_SIZE];
	vector<STaskDt*> VecTask;
	vector<SGoodsDt*> VecItem;
};

