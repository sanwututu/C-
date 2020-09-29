#include "stdafx.h"
#include "EnemyMgr.h"
#include "GameMgr.h"
#include "ConfigMgr.h"

//int getTime()
//{
//	return clock() / CLOCKS_PER_SEC;
//}
CEnemyMgr::CEnemyMgr()
:m_nTimer(0)
//,m_nTime(0)
{
	m_nTimer = 0;
}
CEnemyMgr::~CEnemyMgr()
{
}
CEnemy* CEnemyMgr::getEnemy(int nRow, int nCol)
{
	for (int i = 0; i < VecEnemy.size(); i++)
	{
		if (VecEnemy[i]->nRow == nRow && VecEnemy[i]->nCol == nCol)
		{
			return VecEnemy[i];
		}
	}
	CEnemy* enemy = new CEnemy();
	return enemy;
}
void CEnemyMgr::update(){


	srand((unsigned int)time(nullptr));
	m_nTimer++;
	if (m_nTimer > 20){
		m_nTimer = 0;
		int nID = rand() % 3 + 3001;
		//找到该id对应到敌人数据
		SEnemyDt* config = new SEnemyDt();
		config = g_pConfigMgr->m_pEnemyDtMgr->getDataByID(nID);
		//根据敌人数据创建敌人
		CEnemy* enemy = new CEnemy();
		enemy->init(config);

		enemy->nRow = 1;
		enemy->nCol = rand() % 16 + 2;
		VecEnemy.push_back(enemy);
		
	}
	
	for (unsigned int i = 0; i < VecEnemy.size(); i++)
	{
		VecEnemy[i]->update();
	}
	//移除出界敌人
	for (int i = VecEnemy.size() - 1; i >= 0; i--)
	{
		if (VecEnemy[i]->nRow > 14)
		{
			VecEnemy.erase(VecEnemy.begin() + i);
		}
	}
}


