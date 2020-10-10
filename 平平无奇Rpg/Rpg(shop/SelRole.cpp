#include "stdafx.h"
#include "SelRole.h"
#include "ConfigMgr.h"
#include "GameMgr.h"

CSelRole::CSelRole()
{
	m_nState = 0;
	m_VecData = CConfigMgr::getInstance()->m_pRoleDtMgr->getAllData();
}


CSelRole::~CSelRole()
{
}

void CSelRole::update()
{
	if (KEY_DOWN(VK_UP))
	{
		m_nState--;
		if (m_nState < 0)
		{
			m_nState = m_VecData.size() - 1;
		}
	}
	else if(KEY_DOWN(VK_DOWN))
	{
		m_nState++;
		if (m_nState > m_VecData.size() - 1)
		{
			m_nState = 0;
		}
	}
	else if (KEY_DOWN(VK_SPACE))
	{
		//拿到玩家到指针执行initConfig
		CGameMgr::getInstance()->getGameMap()->getPlayer()->initConfig(m_VecData[m_nState]);
		CPlayer* pPlayer = new CPlayer();
		CGameMgr::getInstance()->setState(E_STATE_MAP);
	}
}

void CSelRole::render()
{
	cout << "  ID\tHP\tMP\tACK\tDEF\tNAME\tPic" << endl;
	for (int i = 0; i < m_VecData.size(); i++)
	{
		SRoleDt* pDt = m_VecData[i];
		if (m_nState == i)
		{
			cout << "->";
		}
		else
		{
			cout << "  ";
		}
		cout << pDt->nID << "\t" << pDt->nHp << "\t" << pDt->nMp << "\t" << pDt->nAck
			<< "\t" << pDt->nDef<< "\t" << pDt->strName << "\t" 
			<< pDt->strPic << endl;
	}
}
