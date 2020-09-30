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

		g_pGameMgr->setState(E_STATE_MAP);
	}
	else if (KEY_DOWN(VK_SPACE))
	{
		g_pGameMgr->setState(E_STATE_MAP);

	}
}
void CShop::render()
{
	cout << "  ID\tNAME\tPRICE" << endl;
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
			cout<< pDt->nID << "\t" << pDt->strName << "\t" << pDt->strPrice << endl;
			}
	cout << "   按SPACE选择，按ESC退出" << endl;
}
void CShop::refresh(int nNpcID){

	m_VecData = g_pConfigMgr->m_pGoodsDtMgr->getDataByGoodsID(nNpcID);
}
CShop::~CShop()
{
}
