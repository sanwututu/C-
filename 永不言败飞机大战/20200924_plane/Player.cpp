#include "stdafx.h"
#include "Player.h"
#include "GameMgr.h"

extern CBulletMgr g_bulletMgr;
CPlayer::CPlayer()
{

}

CPlayer::~CPlayer()
{
}
void CPlayer::init(SPlayerDt* config){
	nID = config->nID;
	nBulletID = config->nBulletID;
	strName = config->strName;
	strPic = config->strPic;
	nHp = config->nHp;
	nAck = config->nAck;
}
void CPlayer::update(){

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
		g_pGameMgr->m_pGameMap->g_bulletMgr->addBullet(nBulletID, arrPos[3].nRow, arrPos[3].nCol);
	}
	else if (KEY_DOWN(VK_SHIFT)){
		changeShape();
	}

	/*int nID = g_gameMgr.playerMenu.nPlayerID;
	SPlayerDt config = g_configMgr.playerDtMgr.getDataByID(nID);
	SPlayer g_Player(config);*/

}
void CPlayer::move(int nOffsetX, int nOffsetY)
{
	for (int i = 0; i < 4; i++)
	{
		arrPos[i].nRow += nOffsetX;
		arrPos[i].nCol += nOffsetY;
	}
}
void CPlayer::revert(){
	//返回备份坐标
	for (int i = 0; i < 4; i++){
		arrPos[i].nRow = arrPos[i].nRowBk;
		arrPos[i].nCol = arrPos[i].nColBk;
	}
}
void CPlayer::backup(){
	for (int i = 0; i < 4; i++){
		arrPos[i].nRowBk = arrPos[i].nRow;
		arrPos[i].nColBk = arrPos[i].nCol;
	}
}
void CPlayer::setPosition(int nInRow, int nInCol)
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
void CPlayer::changeShape(){
	
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
//判断第i行第j列是否有玩家格子
bool CPlayer::isExit(int nRow, int nCol)
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
