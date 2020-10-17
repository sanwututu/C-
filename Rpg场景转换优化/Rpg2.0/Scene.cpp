#include "stdafx.h"
#include "Scene.h"


CScene::CScene()
{
}
CScene::~CScene()
{
}
void CScene::render()
{
	if (m_vecChildren.size() > 0)
	{
		//始终拿孩子容器的最后一个节点来渲染
		m_pCurNode = m_vecChildren.back();
		m_pCurNode->render();
	}

}

void CScene::update()
{
	if (m_vecChildren.size() > 0)
	{
		//始终拿孩子容器的最后一个节点来渲染
		m_pCurNode = m_vecChildren.back();
		m_pCurNode->update();
	}
}

void CScene::addChild(CNode* pNode, int nZOrder)
{
	//调用父类的addChild
	CNode::addChild(pNode, nZOrder);
}