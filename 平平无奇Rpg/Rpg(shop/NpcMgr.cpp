#include "stdafx.h"
#include "NpcMgr.h"
#include "ConfigMgr.h"

CNpcMgr::CNpcMgr()
{
	createAllNpc();
}


CNpcMgr::~CNpcMgr()
{
}

void CNpcMgr::createAllNpc()
{
	int nSize = CConfigMgr::getInstance()->m_pNpcDtMgr->getSize();
	for (int i = 0; i < nSize; i++)
	{
		SNpcDt* pData = CConfigMgr::getInstance()->m_pNpcDtMgr->getDataByIndex(i);
		CNpc* pNpc = new CNpc(pData);
		m_VecData.push_back(pNpc);
	}
}
//≤È’“NPC
CNpc* CNpcMgr::getNpc(int nRow, int nCol,int nMapID)
{
	for (CNpc* pNpc : m_VecData)
	{
		if (pNpc->getRow() == nRow && pNpc->getCol() == nCol && pNpc->getMapID()==nMapID )
		{
			return pNpc;
		}
	}
	return nullptr;
}
//ªÒ»°NPC
void CNpcMgr::getNpcData(){
}
