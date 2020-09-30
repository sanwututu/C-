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
	int nSize = g_pConfigMgr->m_pNpcDtMgr->getSize();
	for (int i = 0; i < nSize; i++)
	{
		SNpcDt* pData = g_pConfigMgr->m_pNpcDtMgr->getDataByIndex(i);
		CNpc* pNpc = new CNpc(pData);
		m_VecData.push_back(pNpc);
	}
}
//²éÕÒNPC
CNpc* CNpcMgr::getNpc(int nRow, int nCol)
{
	for (CNpc* pNpc : m_VecData)
	{
		if (pNpc->getRow() == nRow && pNpc->getCol() == nCol)
		{
			return pNpc;
		}
	}
	return nullptr;
}

