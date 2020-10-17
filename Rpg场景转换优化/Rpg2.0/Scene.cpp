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
		//ʼ���ú������������һ���ڵ�����Ⱦ
		m_pCurNode = m_vecChildren.back();
		m_pCurNode->render();
	}

}

void CScene::update()
{
	if (m_vecChildren.size() > 0)
	{
		//ʼ���ú������������һ���ڵ�����Ⱦ
		m_pCurNode = m_vecChildren.back();
		m_pCurNode->update();
	}
}

void CScene::addChild(CNode* pNode, int nZOrder)
{
	//���ø����addChild
	CNode::addChild(pNode, nZOrder);
}