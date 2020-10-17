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
	//场景都是空，什么都没有，当前场景要显示什么，就往这个场景放置什么节点。	
	CScene::update();
}

void CGameMenu::render()
{

	//如果菜单场景挂了其他孩子，那么就优先处理这些孩子的数据更新渲染，菜单自己的数据更新渲染不处理。	
	CScene::render();
}
CGameMenu* CGameMenu::create()
{
	CGameMenu* pRet = new CGameMenu();
	return  pRet;
}