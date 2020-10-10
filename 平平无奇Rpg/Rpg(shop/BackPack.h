#pragma once
#include "DataClass.h"
#include "Player.h"
class CBackPack
{
public:
	CBackPack();
	~CBackPack();

	void setState(int nState);
	void update();
	void render();
	void refresh();
private:
	int m_nState;
	vector<SGoodsDt*> m_VecData;

};

