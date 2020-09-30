#pragma once
#include "DataClass.h"
class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	
	//初始化配置表数据
	void initConfig(SRoleDt* pConfig);
	int getRow();
	int getCol();
	void setRow(int nRow);
	void setCol(int nCol);
	void backup();
	void revert();
	void update();
	void render();
	SYN_THE_SIZE(string, m_strPic, Pic);
	SYN_THE_SIZE(int, m_nHp, Hp);
	SYN_THE_SIZE(int, m_nAck, Ack);
private:
	int m_nRow;
	int m_nCol;
	int m_nRowBk;
	int m_nColBk;
	int m_nID;
	string m_strName;
};

