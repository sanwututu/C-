#pragma once
#include "Node.h"
class CShop:public CNode
{
public:
	CShop();
	~CShop();
	virtual void render();
	virtual void update();
	static CShop* create();
};

