#include "stdafx.h"
#include "MapNode.h"
#include "Shop.h"
#include "Director.h"

CMapNode::CMapNode()
{
}


CMapNode::~CMapNode()
{
}
void CMapNode::update()
{

}
void CMapNode::render()
{
	cout << "µØÍ¼ÏÔÊ¾" << endl;
	if (KEY_DOWN(VK_SPACE))
	{
		CShop* pShop = CShop::create();
		CDirector::getInstance()->getRunningScene()->addChild(pShop);
	}
}
CMapNode* CMapNode::create()
{
	CMapNode* pRet = new CMapNode();
	return pRet;
}
