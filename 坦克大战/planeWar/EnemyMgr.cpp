#include "stdafx.h"
#include "EnemyMgr.h"
#include "ConfigMgr.h"

SEnemyMgr::SEnemyMgr()
:m_nTimer(0)//初始化列表
//, m_nTimer(0)
{
	m_nTimer = 0;
}


SEnemyMgr::~SEnemyMgr()
{
}

void SEnemyMgr::update()
{
	//敌人生成
	m_nTimer++;
	if (m_nTimer > 50)
	{
		m_nTimer = 0;
		//创建敌人
		//随机敌人id
		int nID = rand() % 3 + 3001;
		//找到该id对应到敌人数据
		SEnemyDt config = g_configMgr.enemyDtMgr.getDataByID(nID);
		//根据敌人数据创建敌人
		SEnemy enemy;
		enemy.init(config);
		
		//
		int nRow = 1;
		//2-17
		int nCol = rand() % 16 + 2;
		enemy.setPosition(nRow, nCol);
		VecData.push_back(enemy);
	}

	//敌人移动
	for (SEnemy& enemy : VecData)
	{
		enemy.update();
	}
}

SEnemy SEnemyMgr::getEnemy(int nRow, int nCol)
{
	for (SEnemy enemy :VecData)
	{
		if (enemy.isExit(nRow, nCol))
		{
			return enemy;
		}
	}
	SEnemy enemy;
	return enemy;
}
