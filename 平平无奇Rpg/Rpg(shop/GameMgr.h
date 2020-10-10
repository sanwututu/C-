#pragma once
#include "GameMenu.h"
#include "SelRole.h"
#include "GameMap.h"
#include "Shop.h"
#include "FightScene.h"
#include "BackPack.h"
#include "StatusPanel.h"
#include "TaskPanel.h"
class CGameMgr
{
//���е�
public:
	//���캯��
	CGameMgr();
	//����������������deleteʱ�ص��øö�����������
	~CGameMgr();

	static CGameMgr* getInstance();
	static void destroy();
	void init();
	//�޸���set,��ȡ��get
	//set�ӿ�:���ⲿ�����޸�˽�г�Ա����
	void setState(int nState);
	//get�ӿ�:��ȡ˽�г�Ա������ֵ
	int getState();
	CGameMap* getGameMap();
	CShop* getShop();
	CFightScene* getFightScene();
	CBackPack* getBackPack();
	CStatusPanel* getStatusPanel();
	CTaskPanel* getTaskPanel();
	void update();
	void render();
	//menber
//������:�Լ�����������ܷ���
//protected:
//˽�е�
private:
	static CGameMgr* m_pInstance;
	int m_nState;
	CGameMenu* m_pGameMenu;
	CSelRole* m_pSelRole;
	CGameMap* m_pGameMap;
	CShop* m_pShop;
	CFightScene* m_pFightScene;
	CBackPack* m_pBackPack;
	CStatusPanel* m_pStatusPanel;
	CTaskPanel* m_pTaskPanel;
};
