#pragma once
#include "Node.h"
class CMapNode: public CNode
{
public:
	CMapNode();
	~CMapNode();
	virtual void render();
	virtual void update();
	static CMapNode* create();
};

