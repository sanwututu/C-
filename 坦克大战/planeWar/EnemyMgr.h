#pragma once
#include "Enemy.h"
struct SEnemyMgr
{
public:
	SEnemyMgr();
	~SEnemyMgr();

	void update();
	SEnemy getEnemy(int nRow, int nCol);
	vector<SEnemy> VecData;

	int m_nTimer;
};

