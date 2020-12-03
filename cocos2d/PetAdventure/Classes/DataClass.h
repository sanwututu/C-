#ifndef __DataClass_H__
#define __DataClass_H__
#include "DataBase.h"
struct SLevelDt :public SDataBase
{
	int nCoinLimit;
	string strTile;
};
class CLevelDtMgr :public CDataBaseMgr
{
public:
	virtual void parse(Document& doc);
};

struct SRoleDt :public SDataBase
{
	int nLive;
	string strPet;
};

class CRoleDtMgr :public CDataBaseMgr
{
public:
	virtual void parse(Document& doc);
};
class CLoader
{
public:
	static void load();
};


#endif