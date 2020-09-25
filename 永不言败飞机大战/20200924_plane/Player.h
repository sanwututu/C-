#pragma once
#include "DataStruct.h"

struct Vec2{
	int nRow;
	int nCol;
	int nRowBk;
	int nColBk;
};
struct SPlayer
{
public:

	
	SPlayer();
	~SPlayer();
	void init(SPlayerDt config);
	void revert();
	void setPosition(int nInRow, int nInCol);
	void update();
	void backup();
	void changeShape();
	void move(int nOffsetX,int nOffsetY);
	bool isExit(int nRow, int nCol);
	int nID;
	int nHp;
	int nAck;
	int nBulletID;
	string strName;
	string strPic;
	int nDir = E_DIR_UP;
	Vec2 arrPos[4];
};

