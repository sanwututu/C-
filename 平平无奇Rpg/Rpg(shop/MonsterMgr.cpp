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
//��������
void CMonsterMgr::createMonster(){
	int nSize = CConfigMgr::getInstance()->m_pMonsterDtMgr->getSize();
	for (int i = 0; i < nSize; i++)
	{
		SMonsterDt* pData = CConfigMgr::getInstance()->m_pMonsterDtMgr->getDataByIndex(i);
		CMonster* pMonster = new CMonster(pData);
		pMonster->setRow(rand() % 13 + 1);
		pMonster->setCol(rand() % 17 + 1);
		m_VecData.push_back(pMonster);
	}
}
//����Monster
CMonster* CMonsterMgr::getMonster(int nRow, int nCol, int nMapID)
{
	for (CMonster* pMonster : m_VecData)
	{
		if (pMonster->getRow() == nRow && pMonster->getCol() == nCol &&pMonster->getMapID() == nMapID)
		{
			return pMonster;
		}
	}
	return nullptr;
}
//�õ�Monster
CMonster* CMonsterMgr::gainMonster(int nMonsterID){
	for (CMonster* pMonster : m_VecData)
	{
		if (pMonster->getID() == nMonsterID){
			return pMonster;
		}	
	}
	return nullptr;
}
//����Monster
void CMonsterMgr::delMonster(int nMonsterID){
	for (int i = 0; i < m_VecData.size(); i++){
		if (m_VecData[i]->getID() == nMonsterID){
			m_VecData.erase(m_VecData.begin() + i);
		}
	}
}
