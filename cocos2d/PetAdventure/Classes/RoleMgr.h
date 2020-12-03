#ifndef __RoleMgr_H__
#define __RoleMgr_H__

#include "cocos2d.h"
#include "DataClass.h"
USING_NS_CC;
using namespace std;
class CRoleMgr{
public:
	CRoleMgr();
	~CRoleMgr();
	static CRoleMgr* getInstance();
	void setRoleID(int nRoleID);
	CC_SYNTHESIZE_READONLY(int, m_nRoleID, RoleID);
	CC_SYNTHESIZE_READONLY(SRoleDt*, m_pRoleDt, RoleDt);
private:
	static CRoleMgr* m_pInstance;
};
#endif