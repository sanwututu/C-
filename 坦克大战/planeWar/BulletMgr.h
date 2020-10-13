#pragma once
#include "Bullet.h"


struct SBulletMgr
{
public:
	SBulletMgr();
	~SBulletMgr();
	void addBullet(int nID, int nAck, bool isPlayer, int nRow, int nCol,int nDir);
	void update();
	//��nRow,nCol�е��ӵ�
	SBullet getBullet(int nRow, int nCol);
	vector<SBullet> VecBullet;
};

