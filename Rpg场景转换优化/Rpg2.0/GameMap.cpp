#include "stdafx.h"
#include "GameMap.h"
#include "MapNode.h"

CGameMap::CGameMap()
{
	//Ĭ����ʾ�ڵ�
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
