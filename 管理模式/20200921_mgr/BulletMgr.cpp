#include "stdafx.h"
#include "BulletMgr.h"
#include "GameMgr.h"

extern SGameMgr g_gameMgr;
//extern SPlayer g_Player;

SBulletMgr::SBulletMgr()
{

}
void SBulletMgr::update(){
	bulletDir();
}
void SBulletMgr::loadBullet(){
	VecBullet.push_back(g_Bullet);
	VecBullet[VecBullet.size() - 1].nRow = g_gameMgr.gameMap.g_Player.arrPos[3].nRow;
	VecBullet[VecBullet.size() - 1].nCol = g_gameMgr.gameMap.g_Player.arrPos[3].nCol;
	VecBullet[VecBullet.size() - 1].nDir = g_gameMgr.gameMap.g_Player.nDir;
}
void SBulletMgr::bulletDir(){
	//子弹随飞机方向改变
	for (int i = 0; i < VecBullet.size(); i++){

		if (E_DIR_UP == VecBullet[i].nDir)
		{
			VecBullet[i].nRow--;
		}
		else if (E_DIR_DOWN == VecBullet[i].nDir){
			VecBullet[i].nRow++;
		}
		else if (E_DIR_LEFT == VecBullet[i].nDir){
			VecBullet[i].nCol--;
		}
		else if (E_DIR_RIGHT == VecBullet[i].nDir)
		{
			VecBullet[i].nCol++;
		}
	}
}
bool SBulletMgr::isExit(int nRow, int nCol){
	for (int m = 0; m < VecBullet.size(); m++)
	{
		
		if (VecBullet[m].nRow == nRow && VecBullet[m].nCol == nCol)
		{
			return true;
		}
		
	}
	return false;
}
SBulletMgr::~SBulletMgr()
{
}
