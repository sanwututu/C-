#pragma once
#include "Bullet.h"

class CBulletMgr
{
public:
	CBulletMgr();
	~CBulletMgr();
	void update();
	void addBullet(int nID, int nRow, int nCol);
	CBullet* getBullet(int nRow, int nCol);
	vector<CBullet*> VecBullet;
};

