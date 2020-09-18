// 2020.09.17_homework3.2.cpp : �������̨Ӧ�ó������ڵ㡣
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

	g_Goal.nRow = 1;//��Ŀ�긳��ֵ
	g_Goal.nCol = rand() % 16 + 2;

	for (int i = 1; i < 4; i++){//��������ֵ
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
		if (KEY_DOWN(VK_DOWN)){//�������¼�ʱ
			nMenuState++;
			if (nMenuState>E_MENU_EXIT)
			{
				nMenuState = E_MENU_START;
			}
		}
		else if (KEY_DOWN(VK_UP)){//�������ϼ�ʱ
			nMenuState--;
			if (nMenuState<E_MENU_START)
			{
				nMenuState = E_MENU_EXIT;
			}
		}
		else if (KEY_DOWN(VK_RETURN))//�����س���ʱ
		{
			if (nMenuState == E_MENU_START){//��ѡ�п�ʼ��Ϸʱ
				nGameState = E_STATE_GAME;//�����ͼ
			}
		}

		if (E_STATE_MENU == nGameState)
		{
			cout << "������������������������������" << endl;
			cout << "��������  �ɻ���ս  ����������" << endl;
			cout << "������������������������������" << endl;
			if (nMenuState == E_MENU_START)
			{

				cout << "������  ->��ʼ��Ϸ    ��������" << endl;
				cout << "������    ��Ϸ����    ��������" << endl;
				cout << "������    �˳���Ϸ    ��������" << endl;
			}
			else if (nMenuState == E_MENU_SETTING)
			{
				cout << "������    ��ʼ��Ϸ    ��������" << endl;
				cout << "������  ->��Ϸ����    ��������" << endl;
				cout << "������    �˳���Ϸ    ��������" << endl;
			}
			else if (nMenuState == E_MENU_EXIT)
			{
				cout << "������    ��ʼ��Ϸ    ��������" << endl;
				cout << "������    ��Ϸ����    ��������" << endl;
				cout << "������  ->�˳���Ϸ    ��������" << endl;
			}
			cout << "������������������������������" << endl;
			cout << "������������������������������" << endl;
			cout << "������������������������������" << endl;
		}
		else if (E_STATE_END == nGameState){
			cout << "��Ϸ������" << endl;
		}
		else if (E_STATE_WIN == nGameState){
			cout << "��Ӯ�ˣ�" << endl;
		}
		else if (E_STATE_GAME == nGameState)
		{
			for (int i = 0; i < 4; i++){//�ƶ�ǰ�ȱ��ݷɻ���λ��
				g_Air[i].nRowBk = g_Air[i].nRow;
				g_Air[i].nColBk = g_Air[i].nCol;
			}

			//���Ʒɻ��ƶ�
			if (KEY_DOWN(VK_UP)){//�����ϼ�
				for (int i = 0; i < 4; i++){
					g_Air[i].nRow--;
					g_Air[i].nCol = g_Air[i].nColBk;
				}
				g_Shot.nShotCol = g_Air[0].nCol;
				g_Shot.nShotRow = g_Air[0].nRow - 1;
			}
			else if (KEY_DOWN(VK_DOWN)){//�����¼�
				for (int i = 0; i < 4; i++){
					g_Air[i].nRow++;
					g_Air[i].nCol = g_Air[i].nColBk;
				}
				g_Shot.nShotCol = g_Air[0].nCol;
				g_Shot.nShotRow = g_Air[0].nRow - 1;
			}
			else if (KEY_DOWN(VK_RIGHT)){//�����Ҽ�
				for (int i = 0; i < 4; i++){
					g_Air[i].nCol++;
					g_Air[i].nRow = g_Air[i].nRowBk;
				}
				g_Shot.nShotCol = g_Air[0].nCol;
				g_Shot.nShotRow = g_Air[0].nRow - 1;
			}
			else if (KEY_DOWN(VK_LEFT)){//�������
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
				if (1 == nArrayMap[g_Air[i].nRow][g_Air[i].nCol]){//���ɻ�ײǽʱ ����ԭλ�ò���
					g_Air[i].nRow = g_Air[i].nRowBk;
					g_Air[i].nCol = g_Air[i].nColBk;
				}
				for (int j = 0; j < 4; j++){
					if (g_Air[i].nRow == g_Air[j].nRow && g_Air[i].nCol == g_Air[j].nCol && i != j){//�����ܻ�����ײ,��ײ�󷵻�ԭλ
						for (int m = 0; m < 4; m++)
						{
							g_Air[m].nRow = g_Air[m].nRowBk;
							g_Air[m].nCol = g_Air[m].nColBk;
						}
					}
				}
				if (g_Air[i].nRow == g_Goal.nRow && g_Air[i].nCol == g_Goal.nCol){//��������ײĿ��,��ײ�󷵻�ԭλ
					for (int m = 0; m < 4; m++)
					{
						g_Air[m].nRow = g_Air[m].nRowBk;
						g_Air[m].nCol = g_Air[m].nColBk;
						nGameState = E_STATE_END;
					}
				}
			}

			if (g_Goal.nRow == g_Shot.nShotRow && g_Goal.nCol == g_Shot.nShotCol){//���ӵ�����Ŀ��
				g_Goal.nRow = 1;//Ŀ��ˢ��
				g_Goal.nCol = rand() % 16 + 2;
			}
			else if (g_Goal.nRow == 19)//��Ŀ�������������ǽ
			{
				g_Goal.nRow = 1;//Ŀ��ˢ��
				g_Goal.nCol = rand() % 16 + 2;
			}

			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 20; j++){
					bool bAirCreate = false;//���Ʒɻ����Ƶı���

					for (int m = 0; m < 4; m++){
						if (i == g_Air[m].nRow && j == g_Air[m].nCol){//���Ʒɻ�
							bAirCreate = true;
							break;
						}
					}

					if (1 == nArrayMap[i][j]){//����ǽ
						cout << "��";
					}
					else if (0 == nArrayMap[i][j] && !bAirCreate && (i != g_Goal.nRow || j != g_Goal.nCol) && (i != g_Shot.nShotRow || j != g_Shot.nShotCol)){//����·
						cout << "  ";
					}
					else if (bAirCreate && nArrayMap[i][j] != 1){
						cout << "��";
					}
					else if (i == g_Goal.nRow && j == g_Goal.nCol){//����Ŀ��
						cout << "��";
					}
					else if (i == g_Shot.nShotRow && j == g_Shot.nShotCol){//����Ŀ��
						cout << "��";
					}
				}
				cout << endl;
			}
		}
		system("cls");
	}

	return 0;
}

