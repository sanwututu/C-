#include "stdafx.h"
#include "BackPack.h"
#include "ConfigMgr.h"
#include "GameMgr.h"


CBackPack::CBackPack()
:m_nState(0)
{
}
void CBackPack::setState(int nState)
{
	m_nState = nState;
}
void CBackPack::update()
{
	CPlayer* pPlayer = CGameMgr::getInstance()->getGameMap()->getPlayer();
	SRoleDt* role = CConfigMgr::getInstance()->m_pRoleDtMgr->getDataByID(pPlayer->getID());
	
	if (KEY_DOWN(VK_UP))
	{
		m_nState--;
		if (m_nState < 0)
		{
			m_nState = m_VecData.size() - 1;
		}
	}
	else if (KEY_DOWN(VK_DOWN))
	{
		m_nState++;
		if (m_nState > m_VecData.size() - 1)
		{
			m_nState = 0;
		}
	}
	else if (KEY_DOWN(VK_ESCAPE)){

		CGameMgr::getInstance()->setState(E_STATE_MAP);
	}
	else if (KEY_DOWN(VK_SPACE))
	{
		if (5 == m_VecData[m_nState]->nType){
			//HP
			if (pPlayer->getHp()< role->nHp){
				pPlayer->removeItem(m_VecData[m_nState]);
				pPlayer->setHp(pPlayer->getHp() + m_VecData[m_nState]->nHp);
				if ((pPlayer->getHp() + m_VecData[m_nState]->nHp) > role->nHp){
					pPlayer->setHp(role->nHp);
				}
			}
			
			//MP
			if (pPlayer->getMp()< role->nMp){
				pPlayer->removeItem(m_VecData[m_nState]);
				pPlayer->setMp(pPlayer->getMp() + m_VecData[m_nState]->nMp);
				if ((pPlayer->getMp() + m_VecData[m_nState]->nMp) > role->nMp){
					pPlayer->setMp(role->nMp);
				}
			}
		}//穿装备
		else if (m_VecData[m_nState]->nType < 5){
			pPlayer->equip(m_VecData[m_nState]);
			refresh();
		}
		else if (8 == m_VecData[m_nState]->nType){
			pPlayer->setPet(m_VecData[m_nState]); 
			refresh();
		}
		
	}
	else if (KEY_DOWN(0x51)){//Q键
		//脱下装备
		if (m_VecData[m_nState]->nType < 5){
			pPlayer->removeItem(m_VecData[m_nState]);
		}
		/*if (0 == m_VecData[m_nState]->nType){
			if (1 == pPlayer->pArrItem[0] && 1 == m_VecData[m_nState]->nState){
			pPlayer->pArrItem[0] = 0;
			m_VecData[m_nState]->nState = 0;
			m_VecData[m_nState]->nNum++;
			pPlayer->setAck(pPlayer->getAck() - m_VecData[m_nState]->nAck);
			pPlayer->setDef(pPlayer->getDef() - m_VecData[m_nState]->nDef);
			}
			}
			else if (1 == m_VecData[m_nState]->nType){
			if (1 == pPlayer->pArrItem[1] && 1 == m_VecData[m_nState]->nState){
			pPlayer->pArrItem[1] = 0;
			m_VecData[m_nState]->nState = 0;
			m_VecData[m_nState]->nNum++;
			pPlayer->setAck(pPlayer->getAck() - m_VecData[m_nState]->nAck);
			pPlayer->setDef(pPlayer->getDef() - m_VecData[m_nState]->nDef);
			}
			}
			else if (2 == m_VecData[m_nState]->nType){
			if (1 == pPlayer->pArrItem[2] && 1 == m_VecData[m_nState]->nState){
			pPlayer->pArrItem[2] = 0;
			m_VecData[m_nState]->nState = 0;
			m_VecData[m_nState]->nNum++;
			pPlayer->setAck(pPlayer->getAck() - m_VecData[m_nState]->nAck);
			pPlayer->setDef(pPlayer->getDef() - m_VecData[m_nState]->nDef);
			}
			}
			else if (3 == m_VecData[m_nState]->nType){
			if (1 == pPlayer->pArrItem[3] && 1 == m_VecData[m_nState]->nState){
			pPlayer->pArrItem[3] = 0;
			m_VecData[m_nState]->nState = 0;
			m_VecData[m_nState]->nNum++;
			pPlayer->setAck(pPlayer->getAck() - m_VecData[m_nState]->nAck);
			pPlayer->setDef(pPlayer->getDef() - m_VecData[m_nState]->nDef);
			}
			}
			else if (4 == m_VecData[m_nState]->nType){
			if (1 == pPlayer->pArrItem[4] && 1 == m_VecData[m_nState]->nState){
			pPlayer->pArrItem[4] = 0;
			m_VecData[m_nState]->nState = 0;
			m_VecData[m_nState]->nNum++;
			pPlayer->setAck(pPlayer->getAck() - m_VecData[m_nState]->nAck);
			pPlayer->setDef(pPlayer->getDef() - m_VecData[m_nState]->nDef);
			}
			}

			}*/
	}
}
void CBackPack::render()
{
	cout << "  ID\tNAME\tPIC\tHP\tMP\tACK\tDEF\tPRICE\tNUM" << endl;
	for (int i = 0; i < m_VecData.size(); i++)
	{
		SGoodsDt* pDt = m_VecData[i];
		if (m_nState == i)
		{
			cout << "->";
		}
		else{
			cout << "  ";
		}
		cout << pDt->nID << "\t" << pDt->strName << "\t" << pDt->strPic << "\t" << pDt->nHp << "\t" << pDt->nMp
			<< "\t" << pDt->nAck << "\t" << pDt->nDef << "\t" << pDt->nPrice<< "\t" << pDt->nNum
			<< endl;
	}
	cout << "   使用(SPACE)		取消佩戴(Q)     退出(ESC)" << endl;
}
void CBackPack::refresh(){

	m_VecData = CGameMgr::getInstance()->getGameMap()->getPlayer()->getAllVecItem();
}

CBackPack::~CBackPack()
{
}
