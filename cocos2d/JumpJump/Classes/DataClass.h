#pragma once
#include "DataBase.h"

struct SStarDt :public SDataBase{
	int nScore;
	vector<string>VecImg;
};

class CStarDtMgr :public CDataBaseMgr{
public:
	virtual void parse(Document& doc);
private:
};