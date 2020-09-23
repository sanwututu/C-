#include "stdafx.h"
#include <fstream>
#include "GameMap.h"
#include "BulletMgr.h"

extern SBulletMgr g_bulletMgr;
SGameMap::SGameMap()
{
	
	loadFile("Configs/LevelDt.txt");
	levelDt = VecLevelDt[0];
	g_Player.setPosition(levelDt.nBirthRow, levelDt.nBirthCol);
}

void SGameMap::loadFile(string strPath)
{
	//读取路径中到文件，并将文件内容解析到infile结构体
	ifstream infile(strPath);
	if (infile)
	{
		int nCount = 0;
		infile >> nCount;
		for (int i = 0; i < nCount; i++)
		{
			
			infile >> levelDt.strName >> levelDt.nID >> levelDt.nRowSize >> levelDt.nColSize >> levelDt.nBirthRow >> levelDt.nBirthCol;
			for (int m = 0; m < levelDt.nRowSize; m++)
			{
				for (int n = 0; n < levelDt.nColSize; n++)
				{
					infile >> levelDt.arrMap[m][n];
				}
			}
			VecLevelDt.push_back(levelDt);
		}
	}
	infile.close();
}

void SGameMap::transfer(){

}
void SGameMap::update()
{

	g_Player.update();
	g_bulletMgr.update();

	for (int i = 0; i < 4; i++){
		int nValue = levelDt.arrMap[g_Player.arrPos[i].nRow][g_Player.arrPos[i].nCol];
		//判断是否撞墙了
		if (1 == nValue)
		{
			g_Player.revert();
		}
		else if (nValue > 1000)
		{
			levelDt = VecLevelDt[nValue - 1001];
			g_Player.setPosition(levelDt.nBirthRow, levelDt.nBirthCol);
			g_Player.backup();
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
			if (1 == nValue)
			{
				cout << "■";
			}
			else if (g_Player.isExit(i, j))
			{
				cout << "□";
			}
			else if (nValue > 1000)
			{
				cout << "◎";
			}
			else if (g_bulletMgr.isExit(i, j))
			{
				cout << "▲";
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
