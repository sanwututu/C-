#include "DataClass.h"

void CStarDtMgr::parse(Document& doc){
	for (int i = 0; i < doc.Size(); i++){
		rapidjson::Value& vStarDt = doc[i];
		SStarDt* pData = new SStarDt();
		pData->nID = vStarDt["id"].GetInt();
		pData->nScore = vStarDt["score"].GetInt();
		rapidjson::Value& vimg = vStarDt["imgs"];
		for (int j = 0; j < vimg.Size(); j++){
			string strImg = vimg[j].GetString();
			pData->VecImg.push_back(strImg);
		}
		m_vecDatas.push_back(pData);
		int j = 0;
	}
}