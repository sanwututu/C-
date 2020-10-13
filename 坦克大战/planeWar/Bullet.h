#pragma once
#include "DataStruct.h"
class SBullet
{
public:
	SBullet();
	SBullet(SBulletDt config);
	~SBullet();

	void update();
	bool isPlayer;
	int nID;
	int nRow;
	int nCol;
	int nSpeed;
	int nAck;
	int nDir;
	string strName;
	string strPic;
};

