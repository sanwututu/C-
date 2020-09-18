// 2020.09.17_homework3.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;
#define KEY_DOWN(vk_code)(GetAsyncKeyState(vk_code)&0x8000?1:0)

enum{
	E_STATE_MENU,
	E_STATE_GAME,
	E_STATE_END,
	E_STATE_WIN
};
enum{
	E_MENU_START,
	E_MENU_SETTING,
	E_MENU_EXIT
};
struct sData
{
	int nRow;
	int nCol;
	int nRowBk;
	int nColBk;
};
struct sShot{
	int nShotRow;
	int nShotCol;
};

int _tmain(int argc, _TCHAR* argv[])
{
	sData g_Air[4];
	sData g_Goal;
	sShot g_Shot;

	int rowDir = 0;
	int colDir = 0;

	g_Goal.nRow = 1;//给目标赋初值
	g_Goal.nCol = rand() % 16 + 2;

	for (int i = 1; i < 4; i++){//给机身赋初值
		g_Air[i].nRow = 18;
		g_Air[i].nCol = 8 + i;
	}
	g_Air[0].nRow = 17;
	g_Air[0].nCol = 10;

	g_Shot.nShotCol = g_Air[0].nCol;
	g_Shot.nShotRow = g_Air[0].nRow - 1;

	int nArrayMap[20][20] =
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	};

	int nMenuState = 0;
	int nGameState = 0;

	while (true){
		if (KEY_DOWN(VK_DOWN)){//当按向下键时
			nMenuState++;
			if (nMenuState>E_MENU_EXIT)
			{
				nMenuState = E_MENU_START;
			}
		}
		else if (KEY_DOWN(VK_UP)){//当按向上键时
			nMenuState--;
			if (nMenuState<E_MENU_START)
			{
				nMenuState = E_MENU_EXIT;
			}
		}
		else if (KEY_DOWN(VK_RETURN))//当按回车键时
		{
			if (nMenuState == E_MENU_START){//当选中开始游戏时
				nGameState = E_STATE_GAME;//进入地图
			}
		}

		if (E_STATE_MENU == nGameState)
		{
			cout << "□□□□□□□□□□□□□□□" << endl;
			cout << "□□□□  飞机大战  □□□□□" << endl;
			cout << "□□□□□□□□□□□□□□□" << endl;
			if (nMenuState == E_MENU_START)
			{

				cout << "□□□  ->开始游戏    □□□□" << endl;
				cout << "□□□    游戏设置    □□□□" << endl;
				cout << "□□□    退出游戏    □□□□" << endl;
			}
			else if (nMenuState == E_MENU_SETTING)
			{
				cout << "□□□    开始游戏    □□□□" << endl;
				cout << "□□□  ->游戏设置    □□□□" << endl;
				cout << "□□□    退出游戏    □□□□" << endl;
			}
			else if (nMenuState == E_MENU_EXIT)
			{
				cout << "□□□    开始游戏    □□□□" << endl;
				cout << "□□□    游戏设置    □□□□" << endl;
				cout << "□□□  ->退出游戏    □□□□" << endl;
			}
			cout << "□□□□□□□□□□□□□□□" << endl;
			cout << "□□□□□□□□□□□□□□□" << endl;
			cout << "□□□□□□□□□□□□□□□" << endl;
		}
		else if (E_STATE_END == nGameState){
			cout << "游戏结束！" << endl;
		}
		else if (E_STATE_WIN == nGameState){
			cout << "你赢了！" << endl;
		}
		else if (E_STATE_GAME == nGameState)
		{
			for (int i = 0; i < 4; i++){//移动前先备份飞机的位置
				g_Air[i].nRowBk = g_Air[i].nRow;
				g_Air[i].nColBk = g_Air[i].nCol;
			}

			//控制飞机移动
			if (KEY_DOWN(VK_UP)){//按向上键
				for (int i = 0; i < 4; i++){
					g_Air[i].nRow--;
					g_Air[i].nCol = g_Air[i].nColBk;
				}
				g_Shot.nShotCol = g_Air[0].nCol;
				g_Shot.nShotRow = g_Air[0].nRow - 1;
			}
			else if (KEY_DOWN(VK_DOWN)){//按向下键
				for (int i = 0; i < 4; i++){
					g_Air[i].nRow++;
					g_Air[i].nCol = g_Air[i].nColBk;
				}
				g_Shot.nShotCol = g_Air[0].nCol;
				g_Shot.nShotRow = g_Air[0].nRow - 1;
			}
			else if (KEY_DOWN(VK_RIGHT)){//按向右键
				for (int i = 0; i < 4; i++){
					g_Air[i].nCol++;
					g_Air[i].nRow = g_Air[i].nRowBk;
				}
				g_Shot.nShotCol = g_Air[0].nCol;
				g_Shot.nShotRow = g_Air[0].nRow - 1;
			}
			else if (KEY_DOWN(VK_LEFT)){//按向左键
				for (int i = 0; i < 4; i++){
					g_Air[i].nCol--;
					g_Air[i].nRow = g_Air[i].nRowBk;
				}
				g_Shot.nShotCol = g_Air[0].nCol;
				g_Shot.nShotRow = g_Air[0].nRow - 1;
			}

			g_Shot.nShotRow--;
			g_Goal.nRow++;

			for (int i = 0; i < 4; i++){
				if (1 == nArrayMap[g_Air[i].nRow][g_Air[i].nCol]){//当飞机撞墙时 保持原位置不便
					g_Air[i].nRow = g_Air[i].nRowBk;
					g_Air[i].nCol = g_Air[i].nColBk;
				}
				for (int j = 0; j < 4; j++){
					if (g_Air[i].nRow == g_Air[j].nRow && g_Air[i].nCol == g_Air[j].nCol && i != j){//机身不能互相碰撞,碰撞后返回原位
						for (int m = 0; m < 4; m++)
						{
							g_Air[m].nRow = g_Air[m].nRowBk;
							g_Air[m].nCol = g_Air[m].nColBk;
						}
					}
				}
				if (g_Air[i].nRow == g_Goal.nRow && g_Air[i].nCol == g_Goal.nCol){//机身不能碰撞目标,碰撞后返回原位
					for (int m = 0; m < 4; m++)
					{
						g_Air[m].nRow = g_Air[m].nRowBk;
						g_Air[m].nCol = g_Air[m].nColBk;
						nGameState = E_STATE_END;
					}
				}
			}

			if (g_Goal.nRow == g_Shot.nShotRow && g_Goal.nCol == g_Shot.nShotCol){//当子弹射中目标
				g_Goal.nRow = 1;//目标刷新
				g_Goal.nCol = rand() % 16 + 2;
			}
			else if (g_Goal.nRow == 19)//当目标碰到最下面的墙
			{
				g_Goal.nRow = 1;//目标刷新
				g_Goal.nCol = rand() % 16 + 2;
			}

			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 20; j++){
					bool bAirCreate = false;//控制飞机绘制的变量

					for (int m = 0; m < 4; m++){
						if (i == g_Air[m].nRow && j == g_Air[m].nCol){//绘制飞机
							bAirCreate = true;
							break;
						}
					}

					if (1 == nArrayMap[i][j]){//绘制墙
						cout << "■";
					}
					else if (0 == nArrayMap[i][j] && !bAirCreate && (i != g_Goal.nRow || j != g_Goal.nCol) && (i != g_Shot.nShotRow || j != g_Shot.nShotCol)){//绘制路
						cout << "  ";
					}
					else if (bAirCreate && nArrayMap[i][j] != 1){
						cout << "□";
					}
					else if (i == g_Goal.nRow && j == g_Goal.nCol){//绘制目标
						cout << "◆";
					}
					else if (i == g_Shot.nShotRow && j == g_Shot.nShotCol){//绘制目标
						cout << "▲";
					}
				}
				cout << endl;
			}
		}
		system("cls");
	}

	return 0;
}

