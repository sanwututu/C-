#pragma once
#include "DataStruct.h"
class SEnemy
{
public:
	SEnemy();
	~SEnemy();
	void init(SEnemyDt config);
	void setPosition(int nRow, int nCol);
	void update();
	void move();
	void fire();
	void changeshape();
	void backup();
	void revert();
	bool isExit(int nRow, int nCol);
	int m_nTimer;
	int m_nTimer1;
	int nDir;
	int nID;
	int nHp;
	int nAck;
	int nAckSpeed;
	int nSpeed;
	int nBulletID;
	string strName;
	string strPic;

	Vec2 arrPos[4];
};

