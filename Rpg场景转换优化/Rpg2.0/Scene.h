#pragma once
#include "Node.h"
class CScene : public CNode
{
public:
	CScene();
	~CScene();
	void update();
	void render();
	//��д�����addChild����
	virtual void addChild(CNode* pNode, int nZOrder = 0);
private:
	//��ǰ����Ҫ��Ⱦ�Ľڵ㣨ע�⣺���������ӵ�кܶ�ڵ㣨���ӣ��зŵ���������Ľڵ����ǳ�Ϊ�����ĺ��ӣ���
	CNode* m_pCurNode;
};

