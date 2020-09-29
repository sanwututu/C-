#pragma once
#include "DataStruct.h"

class CEnemy
{
public:
	CEnemy();
	~CEnemy();
	void init(SEnemyDt* config);
	void update();
	bool isExit(int nRow, int nCol);
	int nRow;
	int nCol;
	int nSpeed;
	int nHp;
	int nAck;
	int m_nTimer;
	string strName;
	string strPic;
	int nID;
};

