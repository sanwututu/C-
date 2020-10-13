#pragma once
#include "DataStruct.h"

struct SPlayer
{
public:
	SPlayer();
	~SPlayer();
	void init(SRoleDt config);
	void setPosition(int nInRow, int nInCol);
	bool isExit(int nRow, int nCol);
	void revert();
	void backup();
	void changeShape();
	void move(int nOffsetX, int nOffsetY);
	void update();
	int nDir;
	int nID;
	int nHp;
	int nAck;
	int nBulletID;
	string strName;
	string strPic;
	Vec2 arrPos[4];
};

