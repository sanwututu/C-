#include "stdafx.h"
#include "GameMenu.h"


CGameMenu::CGameMenu()
{
}


CGameMenu::~CGameMenu()
{
}
void CGameMenu::update()
{
	//�������ǿգ�ʲô��û�У���ǰ����Ҫ��ʾʲô�����������������ʲô�ڵ㡣	
	CScene::update();
}

void CGameMenu::render()
{

	//����˵����������������ӣ���ô�����ȴ�����Щ���ӵ����ݸ�����Ⱦ���˵��Լ������ݸ�����Ⱦ������	
	CScene::render();
}
CGameMenu* CGameMenu::create()
{
	CGameMenu* pRet = new CGameMenu();
	return  pRet;
}