#include "stdafx.h"
#include "TaskPanel.h"
#include "ConfigMgr.h"
#include "GameMgr.h"


CTaskPanel::CTaskPanel()
:m_nState(0)
{
}

void CTaskPanel::update()
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
		if (0 == m_VecData[m_nState]->nStates){
			pPlayer->addTask(m_VecData[m_nState]);
			CConfigMgr::getInstance()->m_pTaskDtMgr->changeState(m_VecData[m_nState]->nID);
		}
	}
}

void CTaskPanel::render()
{
	cout << "  ID\t任务\t\t\t描述" << endl;
	for (int i = 0; i < m_VecData.size(); i++)
	{
		STaskDt* pDt = m_VecData[i];
		if (m_nState == i)
		{
			cout << "->";
		}
		else
		{
			cout << "  ";
		}
		cout << pDt->nID << "\t" << pDt->strName << "\t\t" << pDt->strDetail;
		if (0 == pDt->nStates){
			cout << " \t未领取";
		}
		else if (1 == pDt->nStates){

			cout << " \t已领取";
		}
		else if (2 == pDt->nStates){

		}
			
		cout<< endl;
	}
	cout << "   领取(SPACE)   提交(S)    退出(ESC)" << endl;
}
void CTaskPanel::refresh(int nNpcID){

	m_VecData = CConfigMgr::getInstance()->m_pTaskDtMgr->getDataByTaskID(nNpcID);
}
CTaskPanel::~CTaskPanel()
{
}
