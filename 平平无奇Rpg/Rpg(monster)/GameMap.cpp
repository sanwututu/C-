#include "stdafx.h"
#include "GameMap.h"
#include "GameMgr.h"

CGameMap::CGameMap()
{
	m_pLevelDt = g_pConfigMgr->m_pLevelDtMgr->getDataByID(1001);
	m_pPlayer = new CPlayer();
	m_pPlayer->setRow(m_pLevelDt->nBirthRow);
	m_pPlayer->setCol(m_pLevelDt->nBirthCol);
	m_pNpcMgr = new CNpcMgr();
	m_pMonsterMgr = new CMonsterMgr();
}


CGameMap::~CGameMap()
{
}

void CGameMap::update()
{
	m_pPlayer->update();

		int nValue = m_pLevelDt->pArrMap[m_pPlayer->getRow()][m_pPlayer->getCol()];
		//判断是否撞墙了
		if (1 == nValue)
		{
			m_pPlayer->revert();
		}
		//判断进入哪个商店
		//玩家碰NPC
		CNpc* pNpc = m_pNpcMgr->getNpc(m_pPlayer->getRow(), m_pPlayer->getCol());
		if (pNpc){
			g_pGameMgr->getShop()->refresh(pNpc->getID());
			m_pPlayer->revert();
			g_pGameMgr->setState(E_STATE_SHOP);
		}
		//判断碰到怪物
		CMonster* pMonster = m_pMonsterMgr->getMonster(m_pPlayer->getRow(), m_pPlayer->getCol());
		if (pMonster){
			m_pPlayer->revert(); 
			g_pGameMgr->getFightScene()->refresh(pMonster->getID());
			g_pGameMgr->setState(E_STATE_FIGHT);
		}
		        
}

void CGameMap::render()
{
	cout << m_pLevelDt->strName << endl;
	for (int i = 0; i < m_pLevelDt->nRowSize; i++)
	{
		for (int j = 0; j < m_pLevelDt->nColSize; j++)
		{
			//是否有Npc
			CNpc* pNpc = m_pNpcMgr->getNpc(i, j);
			//是否有怪物
			CMonster* pMonster = m_pMonsterMgr->getMonster(i, j);
			if (1 == m_pLevelDt->pArrMap[i][j])
			{
				cout << "■";
			}
			else if (m_pPlayer->getRow() == i && m_pPlayer->getCol() == j)
			{
				m_pPlayer->render();
			}
			else if (pNpc)
			{
				pNpc->render();
				//cout << pNpc->getPic();
			}
			else if (pMonster){
				pMonster->render();
			}
			else{
				cout << "  ";
			}
		}
		cout << endl;
	}
}

CPlayer* CGameMap::getPlayer()
{
	return m_pPlayer;
}
CMonsterMgr* CGameMap::getMonsterMgr()
{
	return m_pMonsterMgr;
}
