// 20200921-������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "time.h"
#include<vector>

using namespace std;
#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code)&0x8000?1:0)

//��ͼ����
int arrMap[25][25] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};
enum DIR
{
	E_DIR_UP,
	E_DIR_LEFT,
	E_DIR_DOWN,
	E_DIR_RIGHT
};
enum GAMESTATE
{
	E_STATE_GAME,
	E_STATE_WIN,
	E_STATE_LOSE
};
struct SBlock
{
	//�����ж�����캯��
	SBlock(){
		nRow = 0;
		nCol = 0;
		nRowBk = 0;
		nColBk = 0;
	}
	SBlock(int nInRow, int nInCol){
		nRow = nInRow;
		nCol = nInCol;
		nRowBk = nInRow;
		nColBk = nInCol;
	}
	int nRow;
	int nCol;
	int nRowBk;
	int nColBk;
};
struct SEnemy{
	int nRow;
	int nCol;
	int nRowBk;
	int nColBk;
	int nEnDir;
	//�����ƶ�
	void enmove(){
		if (nRow > 23){
			nRow = 1;
			nCol = rand() % 22 + 1;
			nCol = rand() % 22 + 1;
			if (nCol < 2){
				nCol = rand() % 22 + 1;
			}
		}
		//���������˶�
		nRow++;
		//��ǽ��ı䷽��
		if (1 == arrMap[nRow][nCol]){
			nEnDir *= -1;
		}
		//�����˶�
		nCol += 1 * (nEnDir);
	}
};
struct SPlayer
{
	SPlayer(int nRow, int nCol, int nInDir){
		arrBlock[1].nRow = nRow;
		arrBlock[1].nCol = nCol;
		arrBlock[0].nRow = nRow;
		arrBlock[0].nCol = nCol - 1;
		arrBlock[2].nRow = nRow;
		arrBlock[2].nCol = nCol + 1;
		arrBlock[3].nRow = nRow - 1;
		arrBlock[3].nCol = nCol;
		nDir = nInDir;
	}
	SBlock arrBlock[4];
	int nDir;
	void changeShape(){
		
			nDir++;

			if (nDir > E_DIR_RIGHT)
			{
				nDir = E_DIR_UP;
			}
			if (E_DIR_UP == nDir)
			{
				arrBlock[0].nRow = arrBlock[1].nRow;
				arrBlock[0].nCol = arrBlock[1].nCol - 1;
				arrBlock[2].nRow = arrBlock[1].nRow;
				arrBlock[2].nCol = arrBlock[1].nCol + 1;
				arrBlock[3].nRow = arrBlock[1].nRow - 1;
				arrBlock[3].nCol = arrBlock[1].nCol;
			}
			else if (E_DIR_DOWN == nDir)
			{
				arrBlock[0].nRow = arrBlock[1].nRow;
				arrBlock[0].nCol = arrBlock[1].nCol + 1;
				arrBlock[2].nRow = arrBlock[1].nRow;
				arrBlock[2].nCol = arrBlock[1].nCol - 1;
				arrBlock[3].nRow = arrBlock[1].nRow + 1;
				arrBlock[3].nCol = arrBlock[1].nCol;
			}
			else if (E_DIR_LEFT == nDir)
			{
				arrBlock[0].nRow = arrBlock[1].nRow + 1;
				arrBlock[0].nCol = arrBlock[1].nCol;
				arrBlock[2].nRow = arrBlock[1].nRow - 1;
				arrBlock[2].nCol = arrBlock[1].nCol;
				arrBlock[3].nRow = arrBlock[1].nRow;
				arrBlock[3].nCol = arrBlock[1].nCol - 1;
			}
			else if (E_DIR_RIGHT == nDir)
			{
				arrBlock[0].nRow = arrBlock[1].nRow - 1;
				arrBlock[0].nCol = arrBlock[1].nCol;
				arrBlock[2].nRow = arrBlock[1].nRow + 1;
				arrBlock[2].nCol = arrBlock[1].nCol;
				arrBlock[3].nRow = arrBlock[1].nRow;
				arrBlock[3].nCol = arrBlock[1].nCol + 1;
			}
		}

	//�ƶ�
	void move(int nOffsetX,int nOffsetY){
		//ʵ���ƶ�
		for (int i = 0; i < 4; i++){
			//����
			arrBlock[i].nRowBk = arrBlock[i].nRow;
			arrBlock[i].nColBk = arrBlock[i].nCol;
			//�ƶ�
			arrBlock[i].nRow += nOffsetX;
			arrBlock[i].nCol += nOffsetY;

		}
	}
	
};

struct SBullet
{
	SBullet(){
		nRow = 0;
		nCol = 0;
		nRowBk = 0;
		nColBk = 0;
	}
	SBullet(int nInRow, int nInCol){
		nRow = nInRow;
		nCol = nInCol;
		nRowBk = nInRow;
		nColBk = nInCol;
	}
	int nRow;
	int nCol;
	int nRowBk;
	int nColBk;
	int nDir;
};

//ʱ�亯��
int getTime()
{
	return clock() / CLOCKS_PER_SEC;
}
int lastTime = 0;


vector<SBullet>Vecbullet;
vector<SBullet>VecenemyBu;

SBullet g_arrBullet;
SBullet g_enBullet;
SPlayer g_Player(23, 15, E_DIR_UP);
SEnemy g_Enemy;

int nGameState = E_STATE_GAME;
//�����¼�
void onKeyEvent(){
	if (KEY_DOWN(VK_UP))
	{
		g_Player.move(-1, 0);

	}
	else if (KEY_DOWN(VK_DOWN))
	{
		g_Player.move(1, 0);
	}
	else if (KEY_DOWN(VK_LEFT))
	{
		g_Player.move(0, -1);
	}
	else if (KEY_DOWN(VK_RIGHT))
	{
		g_Player.move(0, 1);
	}
	else if (KEY_DOWN(VK_SPACE))
	{

		Vecbullet.push_back(g_arrBullet);
		Vecbullet[Vecbullet.size() - 1].nRow = g_Player.arrBlock[3].nRow;
		Vecbullet[Vecbullet.size() - 1].nCol = g_Player.arrBlock[3].nCol;
		Vecbullet[Vecbullet.size() - 1].nDir = g_Player.nDir;
	}
	else if (KEY_DOWN(VK_SHIFT)){
		g_Player.changeShape();
	}
}
//�ӵ��ƶ�
void bulletMove(){
	//�ı䷽���ӵ�
	for (int i = 0; i < Vecbullet.size(); i++)
	{
		if (E_DIR_UP == Vecbullet[i].nDir)
		{
			Vecbullet[i].nRow--;
		}
		else if (E_DIR_DOWN == Vecbullet[i].nDir){
			Vecbullet[i].nRow++;
		}
		else if (E_DIR_LEFT == Vecbullet[i].nDir){
			Vecbullet[i].nCol--;
		}
		else if (E_DIR_RIGHT == Vecbullet[i].nDir)
		{
			Vecbullet[i].nCol++;
		}
	}
}
//��ײ
void collic(){
	//��ײ���
	bool bColliWall = false;
	for (int i = 0; i < 4; i++){
		int nRow = g_Player.arrBlock[i].nRow;
		int nCol = g_Player.arrBlock[i].nCol;
		if (1 == arrMap[nRow][nCol]){
			for (int j = 0; j < 4; j++){
				g_Player.arrBlock[j].nRow = g_Player.arrBlock[j].nRowBk;
				g_Player.arrBlock[j].nCol = g_Player.arrBlock[j].nColBk;
			}
			break;
		}
	}
}
//���ݸ���
void update(){

	int nCount = 0;
	onKeyEvent();
	bulletMove();
	collic();
	//��ʱ�������ӵ�
	int now = getTime();
	if (now - lastTime > 0)
	{
		VecenemyBu.push_back(g_enBullet);
		VecenemyBu[VecenemyBu.size() - 1].nRow = g_Enemy.nRow;
		VecenemyBu[VecenemyBu.size() - 1].nCol = g_Enemy.nCol;
	}
	//���˷��ӵ�
	for (int i = 0; i < VecenemyBu.size(); i++){
		VecenemyBu[i].nRow += 6;
	}
	
	//�ӵ���������
	for (int i = 0; i < Vecbullet.size(); i++){
		if (Vecbullet[i].nRow == g_Enemy.nRow && Vecbullet[i].nCol == g_Enemy.nCol){
			nCount++;
			g_Enemy.nRow = 1;
			g_Enemy.nCol = rand() % 22 + 1;
		}
	}
	//ʧ�ܼ��
	for (int i = 0; i < VecenemyBu.size(); i++){
		for (int j = 0; j < 4; j++){
			if (VecenemyBu[i].nRow == g_Player.arrBlock[j].nRow && VecenemyBu[i].nCol == g_Player.arrBlock[j].nCol){
				nGameState = E_STATE_LOSE;
			}
		}

	}
	//ʤ���ж�
	if (nCount > 3){
		nGameState = E_STATE_WIN;
	}
}
//��Ⱦ
void render(){
	for (int i = 0; i < 25; i++){
		for (int j = 0; j < 25; j++){

			//���ɻ�
			bool bDrawBlock = false;
			for (int m = 0; m <4; m++)
			{
				if (g_Player.arrBlock[m].nRow == i && g_Player.arrBlock[m].nCol == j)
				{
					bDrawBlock = true;
					break;//������ǰѭ��
				}
			}
			//���ӵ�
			bool bDrawBullet = false;
			for (int m = 0; m < Vecbullet.size(); m++)
			{
				if (Vecbullet[m].nRow == i && Vecbullet[m].nCol == j)
				{
					bDrawBullet = true;
					break;//������ǰѭ��
				}
			}
			//�������ӵ�
			bool bEnBullet = false;
			for (int m = 0; m < VecenemyBu.size(); m++)
			{
				if (VecenemyBu[m].nRow == i && VecenemyBu[m].nCol == j)
				{
					bEnBullet = true;
					break;//������ǰѭ��
				}
			}

			if (1 == arrMap[i][j])
			{
				cout << "��";
			}
			else if (bDrawBlock)
			{
				cout << "��";
			}
			else if ((i == g_Enemy.nRow) && (j == g_Enemy.nCol)){
				cout << "��";
			}
			else if (bDrawBullet)
			{
				cout << "��";
			}
			else if (bEnBullet){
				cout << "��";
			}
			else{
				cout << "  ";
			}
		}
		cout << endl;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{



	//�������
	srand((unsigned int)time(nullptr));
	//
	g_Enemy.nRow = 1;
	g_Enemy.nCol = rand() % 22 + 1;
	if (g_Enemy.nCol < 2){
		g_Enemy.nCol = rand() % 22 + 1;
	}
	g_Enemy.nEnDir = 1;
	
	while (true){

		if (E_STATE_GAME == nGameState){
			//�����ƶ�
			g_Enemy.enmove();
			update();
			render();
		}
		else if (E_STATE_WIN == nGameState){

			cout << "YOU WIN!";

		}
		else if (E_STATE_LOSE == nGameState){

			cout << "YOU LOSE!!!!!!!!!!!!!";

		}
		system("cls");
	}
	system("pause");
	return 0;
}






