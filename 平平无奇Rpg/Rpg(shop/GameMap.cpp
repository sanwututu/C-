#include "stdafx.h"
#include "GameMap.h"
#include "GameMgr.h"

CGameMap::CGameMap()
{
	m_pLevelDt = CConfigMgr::getInstance()->m_pLevelDtMgr->getDataByID(1001);
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
		//�ж��Ƿ�ײǽ��
		if (1 == nValue)
		{
			m_pPlayer->revert();
		}
		else if (nValue > 1000)
		{
			//�л���ͼ
			m_pLevelDt = CConfigMgr::getInstance()->m_pLevelDtMgr->getDataByID(nValue);
			m_pPlayer->setPosition(m_pLevelDt->nBirthRow, m_pLevelDt->nBirthCol);
		}
		//�жϽ����ĸ��̵�
		//�����NPC
		CNpc* pNpc = m_pNpcMgr->getNpc(m_pPlayer->getRow(), m_pPlayer->getCol(), m_pLevelDt->nID);
		if (pNpc){
			if (0 == pNpc->getType()){
				CGameMgr::getInstance()->getShop()->refresh(pNpc->getID());
				m_pPlayer->revert();
				CGameMgr::getInstance()->setState(E_STATE_SHOP);
			}
			else if (1 == pNpc->getType()){
				CGameMgr::getInstance()->getTaskPanel()->refresh(pNpc->getID());
				m_pPlayer->revert();
				CGameMgr::getInstance()->setState(E_STATE_TASK);
			}
			
		}
		//�ж���������
		CMonster* pMonster = m_pMonsterMgr->getMonster(m_pPlayer->getRow(), m_pPlayer->getCol(), m_pLevelDt->nID);
		if (pMonster){
			m_pPlayer->revert(); 
			CGameMgr::getInstance()->getFightScene()->refresh(pMonster->getID());
			CGameMgr::getInstance()->setState(E_STATE_FIGHT);
		}
		 //���뱳��
		if (KEY_DOWN(0x50))
		{
			CGameMgr::getInstance()->getBackPack()->refresh();
			CGameMgr::getInstance()->setState(E_STATE_BACKPACK);

		}
		else if (KEY_DOWN(0x53)){
			//�����������

			CGameMgr::getInstance()->setState(E_STATE_STATUSPANEL);
		}
		
}

void CGameMap::render()
{
	cout << m_pLevelDt->strName << endl;
	for (int i = 0; i < m_pLevelDt->nRowSize; i++)
	{
		for (int j = 0; j < m_pLevelDt->nColSize; j++)
		{
			//�Ƿ���Npc
			CNpc* pNpc = m_pNpcMgr->getNpc(i, j, m_pLevelDt->nID);
			//�Ƿ��й���
			CMonster* pMonster = m_pMonsterMgr->getMonster(i, j, m_pLevelDt->nID);
			//��ȡ����
			SPet* pPet = m_pPlayer->gainPet();

			if (1 == m_pLevelDt->pArrMap[i][j])
			{
				cout << "��";
			}
			else if (m_pPlayer->getRow() == i && m_pPlayer->getCol() == j)
			{
				m_pPlayer->render();
			}
			else if (pNpc)
			{
				pNpc->render();
			}
			else if (pMonster){
				pMonster->render();
			}
			else if (pPet && pPet->nCol == j&&pPet->nRow == i){

				cout<<pPet->strPic;
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
CNpcMgr* CGameMap::getNpcMgr()
{
	return m_pNpcMgr;
}

