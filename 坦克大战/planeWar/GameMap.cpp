#include "stdafx.h"
#include <fstream>
#include "GameMap.h"

SGameMap::SGameMap()
{
	levelDt = g_configMgr.levelDtMgr.getDataByID(1001);
	player.setPosition(levelDt.nBirthRow, levelDt.nBirthCol);
}


void SGameMap::update()
{
	player.update();
	//碰墙检测
	for (int i = 0; i < 4; i++)
	{
		int nRow = player.arrPos[i].nRow;
		int nCol = player.arrPos[i].nCol;
		int nValue = levelDt.arrMap[nRow][nCol];
		if (1 == nValue)
		{
			player.revert();
			break;
		}
		else if (nValue > 1000)
		{
			//切换地图
			levelDt = g_configMgr.levelDtMgr.getDataByID(nValue);
			player.setPosition(levelDt.nBirthRow, levelDt.nBirthCol);
			break;
		}
	}
	bulletMgr.update();
	enemyMgr.update();
	//敌人撞墙
	for (SEnemy& enemy : enemyMgr.VecData){
		for (int i = 0; i < 4; i++)
		{
			int nRow = enemy.arrPos[i].nRow;
			int nCol = enemy.arrPos[i].nCol;
			int nValue = levelDt.arrMap[nRow][nCol];
			if (1 == nValue)
			{
				enemy.revert();
				enemy.nDir += rand() % 3;
				break;
			}

		}
	}

	//子弹碰敌人
	for (int i = 0; i < bulletMgr.VecBullet.size(); i++)
	{
		SBullet& bullet = bulletMgr.VecBullet[i];
		if (!bullet.isPlayer)
		{
			continue;//跳出本次循环
		}
		for (int j = 0; j < enemyMgr.VecData.size(); j++)
		{
			SEnemy& enemy = enemyMgr.VecData[j];
			if (enemy.isExit(bullet.nRow, bullet.nCol))
			{
				//碰到了
				//敌人扣血
				enemy.nHp -= bullet.nAck;
				if (enemy.nHp <= 0)
				{
					//移除敌人；
					enemyMgr.VecData.erase(enemyMgr.VecData.begin() + j);
				}
				//子弹移除
				bulletMgr.VecBullet.erase(bulletMgr.VecBullet.begin() + i);
				break;
			}
		}
	}
}

void SGameMap::render()
{
	cout << levelDt.strName << endl;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			int nValue = levelDt.arrMap[i][j];
			SBullet bullet = bulletMgr.getBullet(i, j);
			SEnemy enemy = enemyMgr.getEnemy(i, j);
			if (1 == nValue)
			{
				cout << "■";
			}
			else if (nValue > 1000){
				cout << "门";
			}
			else if (player.isExit(i, j))
			{
				cout << player.strPic;
			}
			else if (bullet.nID > 2000)
			{
				cout << bullet.strPic;
			}
			else if (enemy.nID > 3000)
			{
				cout << enemy.strPic;
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}


// SGameMap::~SGameMap()
// {
// }

//踩到传送门切换到相应到地图