#include "stdafx.h"
#include "FightScene.h"
#include "GameMgr.h"


CFightScene::CFightScene()
:m_nState(0),
m_nFightState(0)
{
}

void CFightScene::update()
{
	if (KEY_DOWN(VK_RIGHT))
	{
		m_nState++;
		if (m_nState > 1)
		{
			m_nState = 0;
		}
	}
	else if(KEY_DOWN(VK_LEFT))
	{
		m_nState--;
		if (m_nState < 0)
		{
			m_nState = 1;
		}
	}
	else if (KEY_DOWN(VK_ESCAPE)){

		cout << "战斗中无法退出" << endl;
	}
	else if (KEY_DOWN(VK_SPACE))
	{
		if (0 == m_nFightState){
			pMonster->setHp(pMonster->getHp() - pPlayer->getAck());
			m_nFightState = 1;
		}

	}
	//怪物攻击
	if (1 == m_nFightState){
		pPlayer->setHp(pPlayer->getHp() - pMonster->getAck());
		m_nFightState = 0;
	}
	//死亡退出
	if (pMonster->getHp() <= 0){
		
		/*g_bulletMgr->VecBullet.erase(g_bulletMgr->VecBullet.begin() + i);*/
		g_pGameMgr->getGameMap()->getMonsterMgr()->delMonster(pMonster->getID());
		g_pGameMgr->setState(E_STATE_MAP);
	}
}
void CFightScene::render()
{
	cout << "进入战斗！" << endl;
	cout << "己方血量：" << pPlayer->getHp()<< endl;
	cout << "敌方血量：" << pMonster->getHp()<< endl;
	cout << "■■■■■■■■■■■■■■■" << endl;
	cout << "■                          ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■   " << pPlayer->getPic()
		<< "             " << getMonster()->getPic() << "      ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■■■■■■■■■■■■■■■" << endl;
	cout << "     攻击          逃跑" << endl;
	if (0 == m_nState){
		cout << "      ▲" << endl;
	}
	else{
		cout << "                    ▲" << endl;
	}
	cout << "_-_-_-_-_-_-_-_-_-_-_" << endl;
	if (0 == m_nFightState){
		cout << "你的回合" << endl;
	}
}
CMonster* CFightScene::getMonster()
{
	return pMonster;
}
CPlayer* CFightScene::getPlayer()
{
	return pPlayer;
}
void CFightScene::refresh(int nMonsterID){

	pMonster = g_pGameMgr->getGameMap()->getMonsterMgr()->gainMonster(nMonsterID);
	pPlayer = g_pGameMgr->getGameMap()->getPlayer();
}
CFightScene::~CFightScene()
{
}
