#include "DataClass.h"
#include "ConfigMgr.h"

void CLevelDtMgr::parse(Document& doc)
{
	for (int i = 0; i < doc.Size(); i++)
	{
		SLevelDt* pData = new SLevelDt();
		rapidjson::Value& vLevel = doc[i];
		pData->nID = vLevel["id"].GetInt();
		pData->nCoinLimit = vLevel["coinLimit"].GetInt();
		pData->strTile = vLevel["mapName"].GetString();
		m_vecDatas.push_back(pData);
	}
}

void CRoleDtMgr::parse(Document& doc)
{
	for (int i = 0; i < doc.Size(); i++)
	{
		SRoleDt* pData = new SRoleDt();
		rapidjson::Value& vRole = doc[i];
		pData->nID = vRole["id"].GetInt();
		pData->nLive = vRole["live"].GetInt();
		pData->strPet = vRole["pet"].GetString();

		m_vecDatas.push_back(pData);
	}
}
void CLoader::load()
{
	CLevelDtMgr* pLevelDtMgr = new CLevelDtMgr();
	pLevelDtMgr->loadFile("Configs/LevelDt.json");
	CConfigMgr::getInstance()->setData("LevelDtMgr", pLevelDtMgr);


	CRoleDtMgr* pRoleDtMgr = new CRoleDtMgr();
	pRoleDtMgr->loadFile("Configs/SelRole.json");
	CConfigMgr::getInstance()->setData("RoleDtMgr", pRoleDtMgr);
}