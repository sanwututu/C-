#include "RoleMgr.h"
#include "ConfigMgr.h"

CRoleMgr* CRoleMgr::m_pInstance = nullptr;
CRoleMgr::CRoleMgr()
:m_nRoleID(0)
, m_pRoleDt(nullptr)
{

}

CRoleMgr::~CRoleMgr()
{

}

CRoleMgr* CRoleMgr::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new CRoleMgr();
	}
	return m_pInstance;
}

void CRoleMgr::setRoleID(int nRoleID)
{
	m_nRoleID = nRoleID;
	m_pRoleDt = static_cast<SRoleDt*>(CConfigMgr::getInstance()->getData("RoleDtMgr")->getDataByID(nRoleID));
}
