#include "stdafx.h"
#include "MenuNode.h"
#include "Director.h"
#include "GameMap.h"


//#include "MenuSetting.h"


CMenuNode::CMenuNode()
{
}


CMenuNode::~CMenuNode()
{
}

void CMenuNode::update()
{
	////�������ý��档
	//CMenuSetting* pMenuSetting = CMenuSetting::create();
	////��ȡ��ǰ������������������ýڵ�������Ӽ��ɡ�
	//CDirector::getInstance()->getRunningScene()->addChild(pMenuSetting);


	//��ȥ�����Լ���update
	if (KEY_DOWN(VK_RETURN))
	{
		if (E_MENU_START == m_nState)
		{
			CGameMap* pGameMap = CGameMap::create();
			CDirector::getInstance()->replaceScene(pGameMap);
		}
		else if (E_MENU_SETTING == m_nState)
		{
			////�������ý��档
			//CMenuSetting* pMenuSetting = CMenuSetting::create();
			////��ȡ��ǰ������������������ýڵ�������Ӽ��ɡ�
			//CDirector::getInstance()->getRunningScene()->addChild(pMenuSetting);

		}

	}
	else if (KEY_DOWN(VK_UP))
	{
		m_nState--;
		if (m_nState < E_MENU_START)
		{
			m_nState = E_MENU_EXIT;
		}
	}
	else if (KEY_DOWN(VK_DOWN))
	{
		m_nState++;
		if (m_nState > E_MENU_EXIT)
		{
			m_nState = E_MENU_START;
		}
	}
}
void CMenuNode::render()
{
	////�����Լ�����Ⱦ
	cout << "������������������������������" << endl;
	cout << "������������������������������" << endl;
	if (E_MENU_START == m_nState)
	{
		cout << "������    ->��Ϸ��ʼ    ������" << endl;
		cout << "������      ��Ϸ����    ������" << endl;
		cout << "������      ��Ϸ�˳�    ������" << endl;
	}
	else if (E_MENU_SETTING == m_nState)
	{
		cout << "������      ��Ϸ��ʼ    ������" << endl;
		cout << "������    ->��Ϸ����    ������" << endl;
		cout << "������      ��Ϸ�˳�    ������" << endl;
	}
	else
	{
		cout << "������      ��Ϸ��ʼ    ������" << endl;
		cout << "������      ��Ϸ����    ������" << endl;
		cout << "������    ->��Ϸ�˳�    ������" << endl;
	}
	cout << "������������������������������" << endl;
	cout << "������������������������������" << endl;
	
}


CMenuNode* CMenuNode::create()
{
	CMenuNode* pRet = new CMenuNode();
	return pRet;
}