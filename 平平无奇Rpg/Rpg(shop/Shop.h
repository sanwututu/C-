#pragma once
#include "DataClass.h"
class CShop
{
public:
	CShop();
	~CShop();
	void setState(int nState);
	void update();
	void render();
	void refresh(int nNpcID);
private:
	int m_nState;
	string shopName;
	vector<SGoodsDt*> m_VecData;
};

