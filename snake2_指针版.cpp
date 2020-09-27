//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "time.h"
#include<vector>

using namespace std;
#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code)&0x8000?1:0)

enum
{
	//枚举值如果没有指定，那么默认从0开始，后一个比前一个多1
	E_STATE_GAME,
	E_STATE_LOSE
};
enum
{
	E_DIR_UP,
	E_DIR_DOWN,
	E_DIR_LEFT,
	E_DIR_RIGHT,
	E_DIR_NONE
};
struct SData
{
	int nRow;
	int nCol;
	int nRowBk;
	int nColBk;
};
SData*p_arrSnake = new SData;
SData*p_Food = new SData;
vector<SData*>Vecsnake;

int _tmain(int argc, _TCHAR* argv[])
{
	int arrMap[20][20] = {};
	//随机种子
	srand((unsigned int)time(nullptr));
	//初始化蛇蛇
	int nDir = E_DIR_NONE;
	int nLen = 1;
	Vecsnake.push_back(p_arrSnake);

	Vecsnake[0]->nRow = rand() % 18 + 1;
	Vecsnake[0]->nCol = rand() % 18 + 1;
	//随机食物
	p_Food->nRow = rand() % 18 + 1;
	p_Food->nCol = rand() % 18 + 1;
	//地图设置
	int arrMap1[20][20] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	//memcpy(拷贝到哪, 从哪里拷贝, 拷贝多大)
	memcpy(arrMap, arrMap1, sizeof(arrMap1));
	int nGameState = E_STATE_GAME;
	while (true){
		//备份蛇头位置
		Vecsnake[0]->nRowBk = Vecsnake[0]->nRow;
		Vecsnake[0]->nColBk = Vecsnake[0]->nCol;
		if (E_STATE_GAME == nGameState){
			//键位控制
			if (KEY_DOWN(VK_UP))
			{
				if (nDir != E_DIR_DOWN){
					nDir = E_DIR_UP;
				}

			}
			else if (KEY_DOWN(VK_DOWN))
			{
				if (nDir != E_DIR_UP){
					nDir = E_DIR_DOWN;
				}
			}
			else if (KEY_DOWN(VK_LEFT))
			{
				if (nDir != E_DIR_RIGHT){
					nDir = E_DIR_LEFT;
				}
			}
			else if (KEY_DOWN(VK_RIGHT))
			{
				if (nDir != E_DIR_LEFT){
					nDir = E_DIR_RIGHT;
				}
			}
			//蛇蛇自己移动
			if (nDir != E_DIR_NONE){
				if (nDir == E_DIR_UP){
					Vecsnake[0]->nRow--;
				}
				else if (nDir == E_DIR_DOWN){
					Vecsnake[0]->nRow++;
				}
				else if (nDir == E_DIR_LEFT){
					Vecsnake[0]->nCol--;
				}
				else if (nDir == E_DIR_RIGHT){
					Vecsnake[0]->nCol++;
				}
				//备份蛇身位置
				for (int i = 1; i < Vecsnake.size(); i++){
					Vecsnake[i]->nRowBk = Vecsnake[i]->nRow;
					Vecsnake[i]->nColBk = Vecsnake[i]->nCol;
				}
				//蛇蛇吃东西
				if ((Vecsnake[0]->nRow == p_Food->nRow) && (Vecsnake[0]->nCol == p_Food->nCol)){
					SData*p_arrSnake = new SData;
					Vecsnake.push_back(p_arrSnake);
					p_Food->nRow = rand() % 18 + 1;
					p_Food->nCol = rand() % 18 + 1;
				}
				//蛇身移动
				for (int i = 1; i < Vecsnake.size(); i++){
					Vecsnake[i]->nRow = Vecsnake[i - 1]->nRowBk;
					Vecsnake[i]->nCol = Vecsnake[i - 1]->nColBk;
				}
			}
			//蛇蛇碰自己
			for (int i = 1; i < Vecsnake.size(); i++){
				if (Vecsnake[0]->nRow == Vecsnake[i]->nRow && Vecsnake[0]->nCol == Vecsnake[i]->nCol)
				{
					nGameState = E_STATE_LOSE;
				}
			}
			//蛇蛇撞墙
			if (1 == arrMap[Vecsnake[0]->nRow][Vecsnake[0]->nCol]){
				nGameState = E_STATE_LOSE;
			}

			//生成地图
			for (int i = 0; i < 20; i++){
				for (int j = 0; j < 20; j++){

					//画蛇蛇
					bool bDrawSnake = false;
					for (int m = 0; m <Vecsnake.size(); m++)
					{
						if (Vecsnake[m]->nRow == i && Vecsnake[m]->nCol == j)
						{
							bDrawSnake = true;
							break;//跳出当前循环
						}
					}

					if (1 == arrMap[i][j])
					{
						cout << "■";
					}
					else if ((i == p_Food->nRow) && (j == p_Food->nCol)){
						cout << "◎";
					}
					else if (bDrawSnake)
					{
						cout << "●";
					}
					else{
						cout << "  ";
					}
				}
				cout << endl;
			}
		}
		else if (E_STATE_LOSE == nGameState){
			cout << "YOU DIE！";
		}

		system("cls");
	}

	return 0;
}




