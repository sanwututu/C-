#pragma once
#include "GameMenu.h"
#include "GameMap.h"
#include "PlayerMenu.h"

class CGameMgr
{
public:
	CGameMgr();
	//����������������deleteʱ�ص��øö�����������
	~CGameMgr();
	//������������ͷ�ļ��У�������ʵ����cpp��
	//��Ա����
	void setState(int nGameState);
	//get�ӿ�:��ȡ˽�г�Ա������ֵ
	int getState();
	void update();
	void render();
	CGameMenu* m_pGameMenu;
	CGameMap* m_pGameMap;
	CPlayerMenu* m_pPlayerMenu;

private:
	int nGameState;
	
	
};
extern CGameMgr* g_pGameMgr;