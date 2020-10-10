#pragma once
#include "Monster.h"
class CMonsterMgr
{
public:
	CMonsterMgr();
	~CMonsterMgr();
	void update();
	void createMonster();
	void delMonster(int nMonsterID);
	CMonster* gainMonster(int nMonsterID);
	CMonster* getMonster(int nRow, int nCol,int nMapID);
private:
	vector<CMonster*> m_VecData;
};

