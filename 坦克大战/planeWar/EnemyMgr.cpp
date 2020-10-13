#include "stdafx.h"
#include "EnemyMgr.h"
#include "ConfigMgr.h"

SEnemyMgr::SEnemyMgr()
:m_nTimer(0)//��ʼ���б�
//, m_nTimer(0)
{
	m_nTimer = 0;
}


SEnemyMgr::~SEnemyMgr()
{
}

void SEnemyMgr::update()
{
	//��������
	m_nTimer++;
	if (m_nTimer > 50)
	{
		m_nTimer = 0;
		//��������
		//�������id
		int nID = rand() % 3 + 3001;
		//�ҵ���id��Ӧ����������
		SEnemyDt config = g_configMgr.enemyDtMgr.getDataByID(nID);
		//���ݵ������ݴ�������
		SEnemy enemy;
		enemy.init(config);
		
		//
		int nRow = 1;
		//2-17
		int nCol = rand() % 16 + 2;
		enemy.setPosition(nRow, nCol);
		VecData.push_back(enemy);
	}

	//�����ƶ�
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
