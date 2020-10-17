#include "stdafx.h"
#include "Node.h"


CNode::CNode()
{
}
CNode::~CNode()
{
}
void CNode::update()
{

}
void CNode::render()
{

}
void CNode::addChild(CNode* pNode, int nZOrder /*= 0*/)
{	//不传次序默认0
	//存储之前要先判断容器里面是否已经有了这个节点。
	//存储到容器。
	if (this->isContainNode(pNode))
	{
		return;
	}
	m_vecChildren.push_back(pNode);
	pNode->setParent(this);
	pNode->setZOrder(nZOrder);
	//只需要去处理孩子里面zorder的排序即可。按从小到大。
	this->sortChildrenByOrder();
}
//判断节点是否存在
bool CNode::isContainNode(CNode* pNode)
{
	for (CNode* pChildNode : m_vecChildren)
	{
		if (pChildNode == pNode)
		{
			return true;
		}
	}
	return false;
}
//移除
void CNode::removeChild(CNode* pNode)
{
	for (int i = 0; i < m_vecChildren.size(); i++)
	{
		if (pNode == m_vecChildren[i])
		{
			m_vecChildren.erase(m_vecChildren.begin() + i);
			return;
		}
	}
}
//排序
void CNode::sortChildrenByOrder()
{
	if (m_vecChildren.size() <= 1)
	{
		return;
	}
	//冒泡排序
	for (int i = 0; i < m_vecChildren.size() - 1; i++)
	{
		for (int j = 0; j < m_vecChildren.size() - i - 1; j++)
		{
			if (m_vecChildren[j]->getZOrder() > m_vecChildren[j + 1]->getZOrder())
			{
				CNode* pNode = m_vecChildren[j];
				m_vecChildren[j] = m_vecChildren[j + 1];
				m_vecChildren[j + 1] = pNode;
			}
		}
	}
}
//通过名字得到孩子节点
CNode* CNode::getChildByName(string strName)
{
	for (int i = 0; i < m_vecChildren.size(); i++)
	{
		if (strName == m_vecChildren[i]->getName())
		{
			return m_vecChildren[i];
		}
	}
	return nullptr;
}

