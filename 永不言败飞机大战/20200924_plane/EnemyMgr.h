#pragma once
#include "Enemy.h"

class CEnemyMgr
{
public:
	CEnemyMgr();
	~CEnemyMgr();
	int m_nTimer;
	void update();
	CEnemy* getEnemy(int nRow, int nCol);
	vector<CEnemy*> VecEnemy;
};

