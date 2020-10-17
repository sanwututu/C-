#include "stdafx.h"
#include "GameMap.h"
#include "MapNode.h"

CGameMap::CGameMap()
{
	//默认显示节点
	this->addChild(CMapNode::create());
}


CGameMap::~CGameMap()
{
}
void CGameMap::update()
{
	CScene::update();
}
void CGameMap::render()
{
	CScene::render();
}
CGameMap* CGameMap::create()
{
	CGameMap* pRet = new CGameMap();
	return pRet;
}
