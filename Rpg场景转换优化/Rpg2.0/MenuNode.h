#pragma once
#include "Node.h"
class CMenuNode: public CNode
{
public:
	CMenuNode();
	~CMenuNode();
	virtual void render();
	virtual void update();
	static CMenuNode* create();
private:
		int m_nState;
};

