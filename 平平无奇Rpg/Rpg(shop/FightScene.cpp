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
	if (KEY_DOWN(VK_ESCAPE)){

		CGameMgr::getInstance()->setState(E_STATE_MAP);
	}
	else if (KEY_DOWN(0x4B))//K¼ü
	{//¹¥»÷
		if (0 == m_nFightState){
			pMonster->setHp(pMonster->getHp() - pPlayer->getAck());
			m_nFightState = 1;
		}
	}
	else if (KEY_DOWN(0x43))
	{
		if (pMonster->getHp()<50){
			cout << "²¶×½³É¹¦£¡" << endl;
			CGameMgr::getInstance()->setState(E_STATE_MAP);
		}
		cout << "²¶×½Ê§°Ü" << endl;
	}
	//¹ÖÎï¹¥»÷
	if (1 == m_nFightState){
		pPlayer->setHp(pPlayer->getHp() - pMonster->getAck());
		m_nFightState = 0;
	}
	
	//ËÀÍöÍË³ö
	if (pMonster->getHp() <= 0){
		
		/*g_bulletMgr->VecBullet.erase(g_bulletMgr->VecBullet.begin() + i);*/
		CGameMgr::getInstance()->getGameMap()->getMonsterMgr()->delMonster(pMonster->getID());
		CGameMgr::getInstance()->setState(E_STATE_MAP);
	}
}
void CFightScene::render()
{
	cout << "½øÈëÕ½¶·£¡" << endl;
	cout << "¼º·½ÑªÁ¿£º" << pPlayer->getHp()<< endl;
	cout << "µÐ·½ÑªÁ¿£º" << pMonster->getHp()<< endl;
	cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << endl;
	cout << "¡ö                          ¡ö" << endl;
	cout << "¡ö                          ¡ö" << endl;
	cout << "¡ö   " << pPlayer->getPic()
		<< "             " << getMonster()->getPic() << "      ¡ö" << endl;
	cout << "¡ö                          ¡ö" << endl;
	cout << "¡ö                          ¡ö" << endl;
	cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << endl;
	cout << "     ¹¥»÷(K)    ²¶×½(C)    ÌÓÅÜ(ESC)" << endl;
	/*if (0 == m_nState){
		cout << "      ¡ø" << endl;
	}
	else{
		cout << "                    ¡ø" << endl;
	}*/
	cout << "_-_-_-_-_-_-_-_-_-_-_" << endl;
	if (0 == m_nFightState){
		cout << "ÄãµÄ»ØºÏ" << endl;
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

	pMonster = CGameMgr::getInstance()->getGameMap()->getMonsterMgr()->gainMonster(nMonsterID);
	pPlayer = CGameMgr::getInstance()->getGameMap()->getPlayer();
}
CFightScene::~CFightScene()
{
}
