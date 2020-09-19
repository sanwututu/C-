// 20200917-������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "time.h"

using namespace std;
#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code)&0x8000?1:0)

enum
{
	//ö��ֵ���û��ָ������ôĬ�ϴ�0��ʼ����һ����ǰһ����1
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
SData g_arrSnake[15] = {};
SData g_Food;


int _tmain(int argc, _TCHAR* argv[])
{
	int arrMap[20][20] = {};
	//�������
	srand((unsigned int)time(nullptr));
	//��ʼ������
	int nDir = E_DIR_NONE;
	int nLen = 1;
	g_arrSnake[0].nRow = rand() % 18 + 1;
	g_arrSnake[0].nCol = rand() % 18 + 1;
	//���ʳ��
	g_Food.nRow = rand() % 18 + 1;
	g_Food.nCol = rand() % 18 + 1;
	//��ͼ����
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
	//memcpy(��������, ��������, �������)
	memcpy(arrMap, arrMap1, sizeof(arrMap1));
	int nGameState = E_STATE_GAME;
	while (true){
		//������ͷλ��
		g_arrSnake[0].nRowBk = g_arrSnake[0].nRow;
		g_arrSnake[0].nColBk = g_arrSnake[0].nCol;
		if (E_STATE_GAME == nGameState){
			//��λ����
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
			//�����Լ��ƶ�
			if (nDir != E_DIR_NONE){
				if (nDir == E_DIR_UP){
					g_arrSnake[0].nRow--;
				}
				else if (nDir == E_DIR_DOWN){
					g_arrSnake[0].nRow++;
				}
				else if (nDir == E_DIR_LEFT){
					g_arrSnake[0].nCol--;
				}
				else if (nDir == E_DIR_RIGHT){
					g_arrSnake[0].nCol++;
				}
				//��������λ��
				for (int i = 1; i < 15; i++){
					g_arrSnake[i].nRowBk = g_arrSnake[i].nRow;
					g_arrSnake[i].nColBk = g_arrSnake[i].nCol;
				}
				//���߳Զ���
				if ((g_arrSnake[0].nRow == g_Food.nRow) && (g_arrSnake[0].nCol == g_Food.nCol)){
					nLen++;
					g_Food.nRow = rand() % 18 + 1;
					g_Food.nCol = rand() % 18 + 1;
				}
				//�����ƶ�
				for (int i = 1; i < 15; i++){
					g_arrSnake[i].nRow = g_arrSnake[i - 1].nRowBk;
					g_arrSnake[i].nCol = g_arrSnake[i - 1].nColBk;
				}
			}
			//�������Լ�
			for (int i = 1; i < 15; i++){
				if (g_arrSnake[0].nRow == g_arrSnake[i].nRow && g_arrSnake[0].nCol == g_arrSnake[i].nCol)
				{
					nGameState = E_STATE_LOSE;
				}
			}
			//����ײǽ
			if (1 == arrMap[g_arrSnake[0].nRow][g_arrSnake[0].nCol]){
				nGameState = E_STATE_LOSE;
			}
			
			//���ɵ�ͼ
			for (int i = 0; i < 20; i++){
				for (int j = 0; j < 20; j++){

					//������
					bool bDrawSnake = false;
					for (int m = 0; m <nLen; m++)
					{
						if (g_arrSnake[m].nRow == i && g_arrSnake[m].nCol == j)
						{
							bDrawSnake = true;
							break;//������ǰѭ��
						}
					}

					if (1 == arrMap[i][j])
					{
						cout << "��";
					}
					else if ((i == g_Food.nRow) && (j == g_Food.nCol)){
						cout << "��";
					}
					else if (bDrawSnake)
					{
						cout << "��";
					}
					else{
						cout << "  ";
					}
				}
				cout << endl;
			}
		}else if (E_STATE_LOSE == nGameState){
			cout << "YOU DIE��";
		}
		
				system("cls");
	}

	return 0;
}

