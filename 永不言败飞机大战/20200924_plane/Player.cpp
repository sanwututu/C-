#include "stdafx.h"
#include "Player.h"
#include "GameMgr.h"

extern SBulletMgr g_bulletMgr;
SPlayer::SPlayer()
{

	nID = g_gameMgr.playerMenu.nPlayerID;

}
//SPlayer::SPlayer(SPlayerDt config)
//{
//	
//}
SPlayer::~SPlayer()
{
}
void SPlayer::init(SPlayerDt config){
	nID = config.nID;
	nBulletID = config.nBulletID;
	strName = config.strName;
	strPic = config.strPic;
	nHp = config.nHp;
	nAck = config.nAck;
}
void SPlayer::update(){
	backup();
	if (KEY_DOWN(VK_UP))
	{
		move(-1, 0);
	}
	else if (KEY_DOWN(VK_DOWN))
	{
		move(1, 0);
	}
	else if (KEY_DOWN(VK_LEFT))
	{
		move(0, -1);
	}
	else if (KEY_DOWN(VK_RIGHT))
	{
		move(0, 1);
	}
	else if (KEY_DOWN(VK_SPACE)){
		/*g_bulletMgr.loadBullet();*//*
		int nBulletID = g_gameMgr.gameMap.g_Player.nBulletID;*/
		g_gameMgr.gameMap.g_bulletMgr.addBullet(nBulletID, arrPos[3].nRow, arrPos[3].nCol);
	}
	else if (KEY_DOWN(VK_SHIFT)){
		changeShape();
	}

	/*int nID = g_gameMgr.playerMenu.nPlayerID;
	SPlayerDt config = g_configMgr.playerDtMgr.getDataByID(nID);
	SPlayer g_Player(config);*/

}
void SPlayer::move(int nOffsetX, int nOffsetY)
{
	for (int i = 0; i < 4; i++)
	{
		arrPos[i].nRow += nOffsetX;
		arrPos[i].nCol += nOffsetY;
	}
}
void SPlayer::revert(){
	//���ر�������
	for (int i = 0; i < 4; i++){
		arrPos[i].nRow = arrPos[i].nRowBk;
		arrPos[i].nCol = arrPos[i].nColBk;
	}
}
void SPlayer::backup(){
	for (int i = 0; i < 4; i++){
		arrPos[i].nRowBk = arrPos[i].nRow;
		arrPos[i].nColBk = arrPos[i].nCol;
	}
}
void SPlayer::setPosition(int nInRow, int nInCol)
{ 
	arrPos[0].nRow = nInRow;
	arrPos[0].nCol = nInCol-1;
	arrPos[1].nRow = nInRow;
	arrPos[1].nCol = nInCol;
	arrPos[2].nRow = nInRow;
	arrPos[2].nCol = nInCol + 1;
	arrPos[3].nRow = nInRow - 1;
	arrPos[3].nCol = nInCol;


}
void SPlayer::changeShape(){
	
	nDir++;

	if (nDir > E_DIR_RIGHT)
	{
		nDir = E_DIR_UP;
	}
	if (E_DIR_UP == nDir)
	{
		arrPos[0].nRow = arrPos[1].nRow;
		arrPos[0].nCol = arrPos[1].nCol - 1;
		arrPos[2].nRow = arrPos[1].nRow;
		arrPos[2].nCol = arrPos[1].nCol + 1;
		arrPos[3].nRow = arrPos[1].nRow - 1;
		arrPos[3].nCol = arrPos[1].nCol;
	}
	else if (E_DIR_DOWN == nDir)
	{
		arrPos[0].nRow = arrPos[1].nRow;
		arrPos[0].nCol = arrPos[1].nCol + 1;
		arrPos[2].nRow = arrPos[1].nRow;
		arrPos[2].nCol = arrPos[1].nCol - 1;
		arrPos[3].nRow = arrPos[1].nRow + 1;
		arrPos[3].nCol = arrPos[1].nCol;
	}
	else if (E_DIR_LEFT == nDir)
	{
		arrPos[0].nRow = arrPos[1].nRow + 1;
		arrPos[0].nCol = arrPos[1].nCol;
		arrPos[2].nRow = arrPos[1].nRow - 1;
		arrPos[2].nCol = arrPos[1].nCol;
		arrPos[3].nRow = arrPos[1].nRow;
		arrPos[3].nCol = arrPos[1].nCol - 1;
	}
	else if (E_DIR_RIGHT == nDir)
	{
		arrPos[0].nRow = arrPos[1].nRow - 1;
		arrPos[0].nCol = arrPos[1].nCol;
		arrPos[2].nRow = arrPos[1].nRow + 1;
		arrPos[2].nCol = arrPos[1].nCol;
		arrPos[3].nRow = arrPos[1].nRow;
		arrPos[3].nCol = arrPos[1].nCol + 1;
	}
}
//�жϵ�i�е�j���Ƿ�����Ҹ���
bool SPlayer::isExit(int nRow, int nCol)
{
	for (int m = 0; m < 4; m++)
	{
		if (arrPos[m].nRow == nRow && arrPos[m].nCol == nCol)
		{
			return true;
		}
	}
	return false;
}
