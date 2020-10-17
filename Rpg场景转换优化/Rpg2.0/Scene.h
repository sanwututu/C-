#pragma once
#include "Node.h"
class CScene : public CNode
{
public:
	CScene();
	~CScene();
	void update();
	void render();
	//重写父类的addChild函数
	virtual void addChild(CNode* pNode, int nZOrder = 0);
private:
	//当前场景要渲染的节点（注意：场景里面会拥有很多节点（孩子：有放到场景里面的节点我们称为场景的孩子））
	CNode* m_pCurNode;
};

