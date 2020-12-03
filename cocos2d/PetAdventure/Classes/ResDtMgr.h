#ifndef __ResDtMgr_H__
#define __ResDtMgr_H__
#include <string>
#include <vector>
#include "cocos2d.h"
#include <map>
#include "json/document.h"
#include "json/rapidjson.h"
using namespace std;
USING_NS_CC;

struct SResDt
{
	vector<string> VecPng;
	vector<string> VecPlist;
	vector<string> VecAudio;
};

class CResDtMgr
{
public:
	CResDtMgr();
	~CResDtMgr();
	static CResDtMgr* getInstance();

	void loadFile(const string& strFile);
	SResDt* getData(string strKey);
private:
	static CResDtMgr* m_pInstance;
	map<string, SResDt*> m_mapData;
};

#endif