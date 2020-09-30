#include "stdafx.h"
#include "MonsterMgr.h"
#include "GameMgr.h"
#include "ConfigMgr.h"

CMonsterMgr::CMonsterMgr()
{
	createMonster();
}


CMonsterMgr::~CMonsterMgr()
{
}
//创建怪物
void CMonsterMgr::createMonster(){
	int nSize = g_pConfigMgr->m_pMonsterDtMgr->getSize();
	for (int i = 0; i < nSize; i++)
	{
		SMonsterDt* pData = g_pConfigMgr->m_pMonsterDtMgr->getDataByIndex(i);
		CMonster* pMonster = new CMonster(pData);
		pMonster->setRow(rand() % 13 + 1);
		pMonster->setCol(rand() % 17 + 1);
		m_VecData.push_back(pMonster);
	}
}
//查找Monster
CMonster* CMonsterMgr::getMonster(int nRow, int nCol)
{
	for (CMonster* pMonster : m_VecData)
	{
		if (pMonster->getRow() == nRow && pMonster->getCol() == nCol)
		{
			return pMonster;
		}
	}
	return nullptr;
}
//得到Monster
CMonster* CMonsterMgr::gainMonster(int nMonsterID){
	for (CMonster* pMonster : m_VecData)
	{
		if (pMonster->getID() == nMonsterID){
			return pMonster;
		}	
	}
	return nullptr;
}
//消除Monster
void CMonsterMgr::delMonster(int nMonsterID){
	for (int i = 0; i < m_VecData.size(); i++){
		if (m_VecData[i]->getID() == nMonsterID){
			m_VecData.erase(m_VecData.begin() + i);
		}
	}
}
