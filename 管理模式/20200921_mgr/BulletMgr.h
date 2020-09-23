#pragma once
#include "Bullet.h"

struct SBulletMgr
{
public:
	SBulletMgr();
	~SBulletMgr();
	void update();
	void loadBullet();
	void bulletDir();
	bool isExit(int nRow, int nCol);
	SBullet g_Bullet;
	vector<SBullet> VecBullet;
};

