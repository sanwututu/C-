#pragma once
#include "Npc.h"
class CNpcMgr
{
public:
	CNpcMgr();
	~CNpcMgr();

	void createAllNpc();
	CNpc* getNpc(int nRow, int nCol);
	void update();
private:
	vector<CNpc*> m_VecData;
};

