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
	else if (KEY_DOWN(0x4B))//K��
	{//����
		if (0 == m_nFightState){
			pMonster->setHp(pMonster->getHp() - pPlayer->getAck());
			m_nFightState = 1;
		}
	}
	else if (KEY_DOWN(0x43))
	{
		if (pMonster->getHp()<50){
			cout << "��׽�ɹ���" << endl;
			CGameMgr::getInstance()->setState(E_STATE_MAP);
		}
		cout << "��׽ʧ��" << endl;
	}
	//���﹥��
	if (1 == m_nFightState){
		pPlayer->setHp(pPlayer->getHp() - pMonster->getAck());
		m_nFightState = 0;
	}
	
	//�����˳�
	if (pMonster->getHp() <= 0){
		
		/*g_bulletMgr->VecBullet.erase(g_bulletMgr->VecBullet.begin() + i);*/
		CGameMgr::getInstance()->getGameMap()->getMonsterMgr()->delMonster(pMonster->getID());
		CGameMgr::getInstance()->setState(E_STATE_MAP);
	}
}
void CFightScene::render()
{
	cout << "����ս����" << endl;
	cout << "����Ѫ����" << pPlayer->getHp()<< endl;
	cout << "�з�Ѫ����" << pMonster->getHp()<< endl;
	cout << "������������������������������" << endl;
	cout << "��                          ��" << endl;
	cout << "��                          ��" << endl;
	cout << "��   " << pPlayer->getPic()
		<< "             " << getMonster()->getPic() << "      ��" << endl;
	cout << "��                          ��" << endl;
	cout << "��                          ��" << endl;
	cout << "������������������������������" << endl;
	cout << "     ����(K)    ��׽(C)    ����(ESC)" << endl;
	/*if (0 == m_nState){
		cout << "      ��" << endl;
	}
	else{
		cout << "                    ��" << endl;
	}*/
	cout << "_-_-_-_-_-_-_-_-_-_-_" << endl;
	if (0 == m_nFightState){
		cout << "��Ļغ�" << endl;
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
