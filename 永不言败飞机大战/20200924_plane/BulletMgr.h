#pragma once
#include "Bullet.h"

struct SBulletMgr
{
public:
	SBulletMgr();
	~SBulletMgr();
	void update();
	void addBullet(int nID, int nRow, int nCol);
	SBullet getBullet(int nRow, int nCol);
	vector<SBullet> VecBullet;
};

