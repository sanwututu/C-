#include "stdafx.h"
#include "Player.h"
#include "ConfigMgr.h"

CPlayer::CPlayer()
{
	m_nRow = 0;
	m_nCol = 0;
	m_nMoney = 5000;
	memset(m_arrEquip, 0, sizeof(m_arrEquip));
	
}


CPlayer::~CPlayer()
{
}

void CPlayer::update()
{
	backup();
	if (m_nPet){
		m_nPet->nRow = m_nRowBk;
		m_nPet->nCol = m_nColBk+1;
	}
	if (KEY_DOWN(VK_UP))
	{
		m_nRow--;
	}
	else if (KEY_DOWN(VK_DOWN))
	{
		m_nRow++;
	}
	else if (KEY_DOWN(VK_LEFT))
	{
		m_nCol--;
	}
	else if (KEY_DOWN(VK_RIGHT))
	{
		m_nCol++;
	}
}


void CPlayer::render()
{
	cout << m_strPic;
}
void CPlayer::addItem(SGoodsDt* pData){

		for (int i = 0; i < VecItem.size(); i++){
			if (VecItem[i]->nID == pData->nID){

				VecItem[i]->nNum++;
				return;
			}
		}
		VecItem.push_back(pData);

}
//装备
void CPlayer::equip(SGoodsDt* pData){
	if (pData->nType > 4){
		return;
	}
	else if (m_arrEquip[pData->nType]){
		
		addItem(m_arrEquip[pData->nType]);
	}
	m_arrEquip[pData->nType] = pData;
	removeItem(pData);
}
//移除
void CPlayer::removeItem(SGoodsDt* pData){
	for (int i = 0; i < VecItem.size(); i++){
		if (VecItem[i]->nID == pData->nID){
			if (VecItem[i]->nNum >1){
				VecItem[i]->nNum--;
			}
			else{
				VecItem.erase(VecItem.begin() + i);
			}
			return;
		}
	}

}
void CPlayer::backup(){
	//备份坐标
	m_nRowBk = m_nRow;
	m_nColBk = m_nCol;

}
void CPlayer::revert(){
	//返回备份坐标
		m_nRow = m_nRowBk;
		m_nCol = m_nColBk;
	
}
//任务
void CPlayer::addTask(STaskDt* pData){
		for (int i = 0; i < VecTask.size(); i++){
			if (VecTask[i]->nID == pData->nID){
				return;
			}
	}
		VecTask.push_back(pData);
}
////宠物
//SPet* CPlayer::getPet(int nInRow, int nInCol){
//	//m_nPet = new SPet();
//	if (!m_nPet)
//	{
//		return nullptr;
//	}
//	if (m_nPet->nRow == nInRow && m_nPet->nCol == nInCol){
//		return m_nPet;
//	}
//	return nullptr;
//}
//返回宠物属性
SPet* CPlayer::gainPet(){
	return m_nPet;
}
void CPlayer::setPet(SGoodsDt* pData){
	if (!m_nPet){
		m_nPet = new SPet();
		m_nPet->nID = pData->nID;
		m_nPet->nAck = pData->nAck;
		m_nPet->nDef = pData->nDef;
		m_nPet->nHp = pData->nHp;
		m_nPet->nMp = pData->nMp;
		m_nPet->strPic = pData->strPic;
		m_nPet->strName = pData->strName;
		m_nPet->nRow = m_nRowBk;
		m_nPet->nCol = m_nColBk;
		removeItem(pData);
	}
}
void CPlayer::setPosition(int nInRow, int nInCol)
{
	m_nRow = nInRow;
	m_nCol = nInCol;
}
//返回容器
vector<SGoodsDt*>& CPlayer::getAllVecItem(){

	return VecItem;
}
SGoodsDt* CPlayer::getAllEquip(int Index){
	return m_arrEquip[Index];
}
vector<STaskDt*>& CPlayer::getAllVecTask(){

	return VecTask;
}
void CPlayer::initConfig(SRoleDt* pConfig)
{
	m_nID = pConfig->nID;
	m_nAck = pConfig->nAck;
	m_nHp = pConfig->nHp;
	m_nMp = pConfig->nMp;
	m_nDef = pConfig->nDef;
	m_strName = pConfig->strName;
	m_strPic = pConfig->strPic;
	
}
