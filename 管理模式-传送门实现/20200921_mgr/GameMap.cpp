#include "stdafx.h"
#include <fstream>
#include "GameMap.h"


SGameMap::SGameMap()
{
	
	nCurLevelID = 1001;
	loadFile("Configs/LevelDt.txt");
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
void SGameMap::colli(){
	//判断是否撞墙了
	if (1 == VecLevelDt[nCurLevelID - 1001].arrMap[g_Player.nRow][g_Player.nCol])
	{
		//返回备份坐标
		g_Player.nRow = g_Player.nRowBk;
		g_Player.nCol = g_Player.nColBk;
	}
}
void SGameMap::transfer(){
	//是否踩到传送门
	int nValue = VecLevelDt[nCurLevelID - 1001].arrMap[g_Player.nRow][g_Player.nCol];
	if (nValue > 1000)
	{
		if (1001 == nValue){
			nCurLevelID = 1001;
		}
		else if (1002 == nValue)
		{
			nCurLevelID = 1002;
		}
		else if (1003 == nValue)
		{
			nCurLevelID = 1003;
		}
		g_Player.nRow = 10;
		g_Player.nCol = 10;
	}
}
void SGameMap::update()
{

	g_Player.nRowBk = g_Player.nRow;
	g_Player.nColBk = g_Player.nCol;
	if (KEY_DOWN(VK_UP))
	{
		g_Player.nRow--;
	}
	else if (KEY_DOWN(VK_DOWN))
	{
		g_Player.nRow++;
	}
	else if (KEY_DOWN(VK_LEFT))
	{
		g_Player.nCol--;
	}
	else if (KEY_DOWN(VK_RIGHT))
	{
		g_Player.nCol++;
	}

	colli();
	transfer();
}

void SGameMap::render()
{
	cout << VecLevelDt[nCurLevelID - 1001].strName << endl;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			int nValue = VecLevelDt[nCurLevelID - 1001].arrMap[i][j];
			if (1 == nValue)
			{
				cout << "■";

			}
			else if ((i == g_Player.nRow) && (j == g_Player.nCol))
			{
				cout << "□";
			}
			else if (nValue > 1000){

				cout << "◎";
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