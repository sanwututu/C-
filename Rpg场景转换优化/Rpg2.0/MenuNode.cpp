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
	////进入设置界面。
	//CMenuSetting* pMenuSetting = CMenuSetting::create();
	////获取当前场景，往里面添加设置节点这个孩子即可。
	//CDirector::getInstance()->getRunningScene()->addChild(pMenuSetting);


	//再去处理自己的update
	if (KEY_DOWN(VK_RETURN))
	{
		if (E_MENU_START == m_nState)
		{
			CGameMap* pGameMap = CGameMap::create();
			CDirector::getInstance()->replaceScene(pGameMap);
		}
		else if (E_MENU_SETTING == m_nState)
		{
			////进入设置界面。
			//CMenuSetting* pMenuSetting = CMenuSetting::create();
			////获取当前场景，往里面添加设置节点这个孩子即可。
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
	////处理自己的渲染
	cout << "■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■" << endl;
	if (E_MENU_START == m_nState)
	{
		cout << "■■■    ->游戏开始    ■■■" << endl;
		cout << "■■■      游戏设置    ■■■" << endl;
		cout << "■■■      游戏退出    ■■■" << endl;
	}
	else if (E_MENU_SETTING == m_nState)
	{
		cout << "■■■      游戏开始    ■■■" << endl;
		cout << "■■■    ->游戏设置    ■■■" << endl;
		cout << "■■■      游戏退出    ■■■" << endl;
	}
	else
	{
		cout << "■■■      游戏开始    ■■■" << endl;
		cout << "■■■      游戏设置    ■■■" << endl;
		cout << "■■■    ->游戏退出    ■■■" << endl;
	}
	cout << "■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■" << endl;
	
}


CMenuNode* CMenuNode::create()
{
	CMenuNode* pRet = new CMenuNode();
	return pRet;
}