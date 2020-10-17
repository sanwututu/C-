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
{	//��������Ĭ��0
	//�洢֮ǰҪ���ж����������Ƿ��Ѿ���������ڵ㡣
	//�洢��������
	if (this->isContainNode(pNode))
	{
		return;
	}
	m_vecChildren.push_back(pNode);
	pNode->setParent(this);
	pNode->setZOrder(nZOrder);
	//ֻ��Ҫȥ����������zorder�����򼴿ɡ�����С����
	this->sortChildrenByOrder();
}
//�жϽڵ��Ƿ����
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
//�Ƴ�
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
//����
void CNode::sortChildrenByOrder()
{
	if (m_vecChildren.size() <= 1)
	{
		return;
	}
	//ð������
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
//ͨ�����ֵõ����ӽڵ�
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

