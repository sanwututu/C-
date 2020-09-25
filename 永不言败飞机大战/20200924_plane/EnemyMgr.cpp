#include "stdafx.h"
#include "EnemyMgr.h"
#include "GameMgr.h"
#include "ConfigMgr.h"

//int getTime()
//{
//	return clock() / CLOCKS_PER_SEC;
//}
SEnemyMgr::SEnemyMgr()
:m_nTimer(0)
//,m_nTime(0)
{
	m_nTimer = 0;
}
SEnemy SEnemyMgr::getEnemy(int nRow, int nCol)
{
	for (int i = 0; i < VecEnemy.size(); i++)
	{
		if (VecEnemy[i].nRow == nRow && VecEnemy[i].nCol == nCol)
		{
			return VecEnemy[i];
		}
	}
	SEnemy enemy;
	return enemy;
}
void SEnemyMgr::update(){


	srand((unsigned int)time(nullptr));
	m_nTimer++;
	if (m_nTimer > 20){
		m_nTimer = 0;
		int nID = rand() % 3 + 3001;
		//找到该id对应到敌人数据
		SEnemyDt config = g_configMgr.enemyDtMgr.getDataByID(nID);
		//根据敌人数据创建敌人
		SEnemy enemy(config);
		SEnemyDt enemyDt = g_configMgr.enemyDtMgr.getDataByID(nID);

		enemy.nSpeed = enemyDt.nSpeed;
		enemy.strName = enemyDt.strName;
		enemy.strPic = enemyDt.strPic;
		enemy.nHp = enemyDt.nHp;
		enemy.nAck = enemyDt.nAck;

		enemy.nRow = 1;
		enemy.nCol = rand() % 16 + 2;
		VecEnemy.push_back(enemy);
		
	}
	
	for (unsigned int i = 0; i < VecEnemy.size(); i++)
	{
		VecEnemy[i].update();
	}
	////移除出界敌人
	//for (int i = VecEnemy.size() - 1; i >= 0; i--)
	//{
	//	if (VecEnemy[i].nRow < 0)
	//	{
	//		VecEnemy.erase(VecEnemy.begin() + i);
	//	}
	//}
}

SEnemyMgr::~SEnemyMgr()
{
}
