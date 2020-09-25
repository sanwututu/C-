#pragma once
#include "Enemy.h"

struct SEnemyMgr
{
public:
	SEnemyMgr();
	~SEnemyMgr();
	int m_nTimer;
	void update();
	SEnemy getEnemy(int nRow, int nCol);
	vector<SEnemy> VecEnemy;
};

