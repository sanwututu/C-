#pragma once
#include "DataStruct.h"

struct SEnemy
{
public:
	SEnemy();
	SEnemy(SEnemyDt config);
	~SEnemy();
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

