#pragma once
#include "Bullet.h"


struct SBulletMgr
{
public:
	SBulletMgr();
	~SBulletMgr();
	void addBullet(int nID, int nAck, bool isPlayer, int nRow, int nCol,int nDir);
	void update();
	//第nRow,nCol列到子弹
	SBullet getBullet(int nRow, int nCol);
	vector<SBullet> VecBullet;
};

