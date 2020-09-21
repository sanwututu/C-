// 20200916-3-box.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <windows.h>
#include <iostream>

using namespace std;
#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code)&0x8000?1:0)

//枚举
enum
{
	//枚举值如果没有指定，那么默认从0开始，后一个比前一个多1
	E_STATE_MENU,
	E_STATE_GAME,
	E_STATE_WIN
	//E_STATE_GAME = 5,
};
enum
{
	E_MENU_START,
	E_MENU_SETTING,
	E_MENU_EXIT
};

struct SData
{
	int nRow;
	int nCol;
	int nRowBk;
	int nColBk;
};

SData g_Player;

SData g_arrBox[3] = {};
int arrMap[15][20] = {};
int _tmain(int argc, _TCHAR* argv[])
{
	int arrMap1[15][20] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1002 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	int arrMap2[15][20] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1001 },
		{ 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	//memcpy(拷贝到哪, 从哪里拷贝, 拷贝多大)
	memcpy(arrMap, arrMap1, sizeof(arrMap1));
	g_Player.nRow = 5;
	g_Player.nCol = 6;
	g_Player.nRowBk = 5;
	g_Player.nColBk = 6;

	for (int i = 0; i < 3; i++)
	{
		g_arrBox[i].nRow = 8 + i;
		g_arrBox[i].nCol = 9;
	}

	int nGameState = E_STATE_MENU;
	int nMenuState = E_MENU_START;

	int arrMap[15][20] = {};
	//memcpy(拷贝到哪, 从哪里拷贝, 拷贝多大)
	memcpy(arrMap, arrMap1, sizeof(arrMap1));

	while (true)
	{
		if (E_STATE_MENU == nGameState)
		{
			if (KEY_DOWN(VK_SPACE))
			{
				if (E_MENU_START == nMenuState)
				{
					nGameState = E_STATE_GAME;
				}

			}
			else if (KEY_DOWN(VK_UP))
			{
				nMenuState--;
				if (nMenuState < E_MENU_START)
				{
					nMenuState = E_MENU_EXIT;
				}
			}
			else if (KEY_DOWN(VK_DOWN))
			{
				nMenuState++;
				if (nMenuState > E_MENU_EXIT)
				{
					nMenuState = E_MENU_START;
				}
			}
			cout << "■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■" << endl;
			if (nMenuState == E_MENU_START){
				cout << "■■■■■  ->游戏开始  ■■■■■■" << endl;
				cout << "■■■■■    游戏设置  ■■■■■■" << endl;
				cout << "■■■■■    游戏结束  ■■■■■■" << endl;
			}
			else if (nMenuState == E_MENU_SETTING){
				cout << "■■■■■    游戏开始  ■■■■■■" << endl;
				cout << "■■■■■  ->游戏设置  ■■■■■■" << endl;
				cout << "■■■■■    游戏结束  ■■■■■■" << endl;
			}
			else{
				cout << "■■■■■    游戏开始  ■■■■■■" << endl;
				cout << "■■■■■    游戏设置  ■■■■■■" << endl;
				cout << "■■■■■  ->游戏结束  ■■■■■■" << endl;
			}
			cout << "■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■" << endl;

		}
		else if (E_STATE_GAME == nGameState)
		{
			//移动前进行坐标备份
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
			//判断是否撞墙了
			if (1 == arrMap[g_Player.nRow][g_Player.nCol])
			{
				//返回备份坐标
				g_Player.nRow = g_Player.nRowBk;
				g_Player.nCol = g_Player.nColBk;
			}
			//玩家碰箱子
			for (int i = 0; i < 3; i++)
			{

				if (g_arrBox[i].nRow == g_Player.nRow && g_arrBox[i].nCol == g_Player.nCol)
				{
					g_arrBox[i].nRow += (g_Player.nRow - g_Player.nRowBk);
					g_arrBox[i].nCol += (g_Player.nCol - g_Player.nColBk);
				}
			}
			//箱子不撞墙
			//箱子之间不碰
			for (int i = 0; i < 3; i++){
				g_arrBox[i].nRowBk = g_arrBox[i].nRow;
				g_arrBox[i].nColBk = g_arrBox[i].nCol;
				if (1 == arrMap[g_arrBox[i].nRow][g_arrBox[i].nCol])
				{
					g_arrBox[i].nRow -= (g_Player.nRow - g_Player.nRowBk);
					g_arrBox[i].nCol -= (g_Player.nCol - g_Player.nColBk);
					g_Player.nRow = g_Player.nRowBk;
					g_Player.nCol = g_Player.nColBk;
				}

				for (int j = 0; j < 3; j++){
					if (g_arrBox[i].nRow == g_arrBox[j].nRow &&g_arrBox[i].nCol == g_arrBox[j].nCol && i != j)
					{
						g_arrBox[i].nRow -= (g_Player.nRow - g_Player.nRowBk);
						g_arrBox[i].nCol -= (g_Player.nCol - g_Player.nColBk);
						g_Player.nRow = g_Player.nRowBk;
						g_Player.nCol = g_Player.nColBk;
					}
				}
			}
			
			//胜利检测
			int nCount = 0;
			for (int i = 0; i < 3; i++)
			{
				if (2 == arrMap[g_arrBox[i].nRow][g_arrBox[i].nCol])
				{
					nCount++;
				}
			}
			if (nCount >= 3)
			{
				//胜利
				nGameState = E_STATE_WIN;
			}
			//是否踩到传送门
			int nValue = arrMap[g_Player.nRow][g_Player.nCol];
			if (nValue > 1000)
			{
				if (1001 == nValue)
				{
					memcpy(arrMap, arrMap1, sizeof(arrMap1));
				}
				else if (1002 == nValue)
				{
					memcpy(arrMap, arrMap2, sizeof(arrMap2));
				}
				g_Player.nRow = 10;
				g_Player.nCol = 10;
			}
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					//第i行第j列是否有箱子
					bool bDrawBox = false;
					for (int m = 0; m < 3; m++)
					{
						if (g_arrBox[m].nRow == i && g_arrBox[m].nCol == j)
						{
							//cout << "箱";
							bDrawBox = true;
							break;//跳出当前循环
						}
					}
					if (1 == arrMap[i][j])
					{
						cout << "■";
					}
					else if ((i == g_Player.nRow) && (j == g_Player.nCol))
					{
						cout << "□";
					}
					else if (arrMap[i][j] > 1000){
						cout << "◎";
					}
					else if (bDrawBox)
					{
						cout << "箱";

					}else if (2 == arrMap[i][j])
					{
						cout << "坑";
					}
					else{
						cout << "  ";
					}
				}
				cout << endl;
			}
		}
		else if (E_STATE_WIN == nGameState){

			cout << "YOU WIN!!!!" << endl;
		}

		system("cls");
	}
	return 0;
}

