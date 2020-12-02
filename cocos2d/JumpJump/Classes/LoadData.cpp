#include "LoadData.h"
#include"DataClass.h"
#include "ConfigMgr.h"
CLoadData::CLoadData(){

	this->initConfigs();
}
CLoadData::~CLoadData(){

}
void CLoadData::initConfigs(){
	//������������
	CStarDtMgr* pStarDtMgr = new CStarDtMgr();
	pStarDtMgr->loadFile("Configs/StarDt.json");
	//
	CConfigMgr::getInstance()->setData("StarDtMgr", pStarDtMgr);
}