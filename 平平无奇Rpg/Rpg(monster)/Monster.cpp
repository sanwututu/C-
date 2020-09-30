#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
	m_nID =0;
	m_nMapID = 0;
	m_nAck = 0;
	m_nHp = 0;
}
CMonster::~CMonster()
{
}
CMonster::CMonster(SMonsterDt* pData)
{
	m_nID = pData->nID;
	m_nMapID = pData->nMapID;
	m_nAck = pData->nAck;
	m_nHp = pData->nHp;
	m_strName = pData->strName;
	m_strPic = pData->strPic;
}
void CMonster::render(){

	cout << m_strPic;
}