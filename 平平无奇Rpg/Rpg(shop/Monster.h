#pragma once
#include "DataClass.h"
class CMonster
{
public:
	CMonster();
	CMonster(SMonsterDt* pData);
	~CMonster();

	void render();
	SYN_THE_SIZE_READONLY(int, m_nID, ID);
	SYN_THE_SIZE(int, m_nAck, Ack);
	SYN_THE_SIZE(int, m_nHp, Hp);
	SYN_THE_SIZE(int, m_nRow, Row);
	SYN_THE_SIZE(int, m_nCol, Col);
	SYN_THE_SIZE(int, m_nMapID, MapID);
	SYN_THE_SIZE_READONLY(string, m_strName, Name);
	SYN_THE_SIZE_READONLY(string, m_strPic, Pic);
};

