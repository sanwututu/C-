#include "ResDtMgr.h"

CResDtMgr* CResDtMgr::m_pInstance = nullptr;
CResDtMgr::CResDtMgr()
{
}

CResDtMgr::~CResDtMgr()
{
	for (map<string, SResDt*>::iterator iter = m_mapData.begin(); iter != m_mapData.end(); ++iter)
	{
		SResDt* pData = iter->second;
		CC_SAFE_DELETE(pData);
	}
	m_mapData.clear();
}

void CResDtMgr::loadFile(const string& strFile)
{
	string strFullPath = FileUtils::getInstance()->fullPathForFilename(strFile);
	string strData = FileUtils::getInstance()->getStringFromFile(strFullPath);
	rapidjson::Document doc;
	doc.Parse(strData.c_str());
	string arrType[3] = { "Common", "Menu", "Game" };
	string arrDataType[3] = { "png", "plist", "audio" };
	for (int i = 0; i < 3; i++)
	{
		SResDt* pData = new SResDt();
		string typeKey = arrType[i];
		rapidjson::Value& vType = doc[typeKey.c_str()];
		for (int j = 0; j < 3; j++)
		{
			rapidjson::Value& vDataType = vType[arrDataType[j].c_str()];
			for (int m = 0; m < vDataType.Size(); m++)
			{
				string str = vDataType[m].GetString();
				if ("png" == arrDataType[j])
				{
					pData->VecPng.push_back(str);
				}
				else if ("plist" == arrDataType[j])
				{
					pData->VecPlist.push_back(str);
				}
				else if ("audio" == arrDataType[j])
				{
					pData->VecAudio.push_back(str);
				}
			}
		}
		m_mapData.insert(pair<string, SResDt*>(typeKey, pData));
	}
	//数组才clear，对象不用
	//doc.Clear();
}

SResDt* CResDtMgr::getData(string strKey)
{
	map<string, SResDt*>::iterator iter = m_mapData.find(strKey);
	if (iter == m_mapData.end())
	{
		return nullptr;
	}
	return iter->second;
}

CResDtMgr* CResDtMgr::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new CResDtMgr();
		m_pInstance->loadFile("Configs/ResData.json");
	}
	return m_pInstance;
}