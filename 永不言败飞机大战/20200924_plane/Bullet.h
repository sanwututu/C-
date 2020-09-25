#pragma once

struct SBullet
{
	
	//
public:
	SBullet();
	~SBullet();
	void update();
	int nRow;
	int nCol;
	int nSpeed;
	int nAck;
	string strName;
	string strPic;
	int nID;
	int nDir;
};

