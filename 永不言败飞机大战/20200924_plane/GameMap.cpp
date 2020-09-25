#include "stdafx.h"
#include "GameMap.h"
#include "ConfigMgr.h"
#include "GameMgr.h"


SGameMap::SGameMap()
{
	levelDt = g_configMgr.levelDtMgr.getDataByID(1001);
	g_Player.setPosition(levelDt.nBirthRow, levelDt.nBirthCol);

}

void SGameMap::update()
{

	g_Player.update();
	g_bulletMgr.update();
	g_enemyMgr.update();

	for (int i = 0; i < 4; i++){
		int nValue = levelDt.arrMap[g_Player.arrPos[i].nRow][g_Player.arrPos[i].nCol];
		//判断是否撞墙了
		if (1 == nValue)
		{
			g_Player.revert();
		}
		else if (nValue > 1000)
		{
			levelDt = g_configMgr.levelDtMgr.getDataByID(nValue);
			g_Player.setPosition(levelDt.nBirthRow, levelDt.nBirthCol); 
			break;
		}
	}
	
	//子弹与敌人消除效果
	for (int i = 0; i < g_bulletMgr.VecBullet.size(); i++)
	{
		SBullet& bullet = g_bulletMgr.VecBullet[i];
		for (int j = 0; j <g_enemyMgr.VecEnemy.size(); j++){
			SEnemy& enemy = g_enemyMgr.VecEnemy[j];
			if (bullet.nRow == enemy.nRow && bullet.nCol == enemy.nCol){
				enemy.nHp -= bullet.nAck;
				if (enemy.nHp <= 0){
					//移除敌人
					g_enemyMgr.VecEnemy.erase(g_enemyMgr.VecEnemy.begin() + j);

				}
				//移除子弹
				g_bulletMgr.VecBullet.erase(g_bulletMgr.VecBullet.begin() + i);
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
			SBullet bullet = g_bulletMgr.getBullet(i, j);
			SEnemy enemy = g_enemyMgr.getEnemy(i, j);


			if (1 == nValue)
			{
				cout << "■";
			}
			else if (g_Player.isExit(i, j))
			{
				cout << g_Player.strPic;
			}
			else if (nValue > 1000)
			{
				cout << "◎";
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
