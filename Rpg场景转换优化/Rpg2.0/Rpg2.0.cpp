// Rpg2.0.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Director.h"
#include "GameMenu.h"
#include "MenuNode.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//�˵�����
	CGameMenu* pGameMenu = CGameMenu::create();
	//�˵�����Ҫ��ʾ�Ľڵ�
	CMenuNode* pMenuNode = CMenuNode::create();
	//�˵�����ʾ�ڵ�Ҫ�ŵ��˵���������
	pGameMenu->addChild(pMenuNode);
	CDirector::getInstance()->replaceScene(pGameMenu);
	//������Ҫ����Ϸ��������֮ǰ����Ҫ֪����һ������ʲô��
	CDirector::getInstance()->run();
	return 0;
}

