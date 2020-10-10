#include "stdafx.h"
#include "Shop.h"
#include "ConfigMgr.h"
#include "GameMgr.h"


CShop::CShop()
:m_nState(0)
{
}

void CShop::setState(int nState)
{
	m_nState = nState;
}
void CShop::update()
{
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
		CPlayer* pPlayer = CGameMgr::getInstance()->getGameMap()->getPlayer();
		if (pPlayer->getMoney() >= m_VecData[m_nState]->nPrice){
			pPlayer->setMoney(pPlayer->getMoney() - m_VecData[m_nState]->nPrice);
			pPlayer->addItem(m_VecData[m_nState]);
		}
		else{
			cout << "½ð±Ò²»¹»£¡" << endl;
		}

	}
}
void CShop::render()
{
	cout <<shopName <<"µÄµêÆÌ"<< endl;
	cout << "ÄãµÄMoney:" << CGameMgr::getInstance()->getGameMap()->getPlayer()->getMoney() << endl;
	cout << "  ID\tNAME\tPIC\tHP\tMP\tACK\tDEF\tPRICE" << endl;
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
			cout << pDt->nID << "\t" << pDt->strName << "\t" << pDt->strPic<< "\t" << pDt->nHp << "\t" << pDt->nMp
				<< "\t" << pDt->nAck << "\t" << pDt->nDef << "\t" << pDt->nPrice << endl;
			}
	cout << "   ¹ºÂò(SPACE)      ÍË³ö(ESC)" << endl;
}
void CShop::refresh(int nNpcID){

	m_VecData = CConfigMgr::getInstance()->m_pGoodsDtMgr->getDataByGoodsID(nNpcID);
	shopName = CConfigMgr::getInstance()->m_pNpcDtMgr->getDataByID(nNpcID)->strName;
}
CShop::~CShop()
{
}
