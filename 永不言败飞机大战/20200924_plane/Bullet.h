#pragma once

class CBullet
{
	
public:
	CBullet();
	~CBullet();
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

