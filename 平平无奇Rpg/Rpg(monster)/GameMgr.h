#pragma once
#include "GameMenu.h"
#include "SelRole.h"
#include "GameMap.h"
#include "Shop.h"
#include "FightScene.h"
class CGameMgr
{
//���е�
public:
	//���캯��
	CGameMgr();
	//����������������deleteʱ�ص��øö�����������
	~CGameMgr();

	void init();
	//�޸���set,��ȡ��get
	//set�ӿ�:���ⲿ�����޸�˽�г�Ա����
	void setState(int nState);
	//get�ӿ�:��ȡ˽�г�Ա������ֵ
	int getState();
	CGameMap* getGameMap();
	CShop* getShop();
	CFightScene* getFightScene();
	void update();
	void render();
	//menber
//������:�Լ�����������ܷ���
//protected:
//˽�е�
private:
	int m_nState;
	CGameMenu* m_pGameMenu;
	CSelRole* m_pSelRole;
	CGameMap* m_pGameMap;
	CShop* m_pShop;
	CFightScene* m_pFightScene;
};

extern CGameMgr* g_pGameMgr;