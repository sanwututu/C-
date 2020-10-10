#include "stdafx.h"
#include "StatusPanel.h"
#include "ConfigMgr.h"
#include "GameMgr.h"


CStatusPanel::CStatusPanel()
{
}

void CStatusPanel::update()
{
	if (KEY_DOWN(VK_ESCAPE)){

		CGameMgr::getInstance()->setState(E_STATE_MAP);
	}
}

void CStatusPanel::render()
{
	
	m_VecItem = CGameMgr::getInstance()->getGameMap()->getPlayer()->getAllVecItem();
	m_VecTask = CGameMgr::getInstance()->getGameMap()->getPlayer()->getAllVecTask();
	CPlayer* pPlayer = CGameMgr::getInstance()->getGameMap()->getPlayer();
	SPet* pPet = pPlayer->gainPet();
	cout << "名字: " << pPlayer->getName() << endl;
	cout << "Hp: " << pPlayer->getHp() << "  Mp: " << pPlayer->getMp() << "  Ack: " << pPlayer->getAck() 
		<< "  Def: " << pPlayer->getDef() << endl;
	cout << "当前金币数：" << pPlayer->getMoney() << endl;
	cout << "---宠物---" << endl;
	cout << pPet->strName << endl;
	cout << "---当前任务---" << endl;
	cout << "ID\t任务\t\t\t描述" << endl;
	for (int i = 0; i < m_VecTask.size(); i++)
	{
		STaskDt* pDt = m_VecTask[i];
		cout << pDt->nID << "\t" << pDt->strName << "\t\t" << pDt->strDetail << endl;
	}
	cout << endl;
	cout << "---装备面板---" << endl;
	cout << "头部:";
	if (pPlayer->getAllEquip(0)){
		cout << pPlayer->getAllEquip(0)->strName;
	}
	cout << endl;
	cout << "手臂：";
	if (pPlayer->getAllEquip(1)){
		cout << pPlayer->getAllEquip(1)->strName;
	} 
	cout << endl;
	cout << "手持：";
	if (pPlayer->getAllEquip(2)){
		cout << pPlayer->getAllEquip(2)->strName;
	}
	cout << endl;
	cout << "腿部：";
	if (pPlayer->getAllEquip(3)){
		cout << pPlayer->getAllEquip(3)->strName;
	}
	cout << endl;
	cout << "脚部：";
	if (pPlayer->getAllEquip(4)){
		cout << pPlayer->getAllEquip(4)->strName;
	} 
		cout << endl;

		cout << "---------" << endl;
		cout << "退出(ESC)" << endl;
}

CStatusPanel::~CStatusPanel()
{
}
