#include "stdafx.h"
#include "Shop.h"
#include "Director.h"

CShop::CShop()
{
	m_strName = "Shop";
}


CShop::~CShop()
{
}
void CShop::update()
{
	if (KEY_DOWN(VK_SPACE))
	{
	}
	if (KEY_DOWN(VK_ESCAPE))
	{
		//������һ����ʾ���ڣ�ֻ��Ҫ�õ���ǰ�������������ӣ���ǰҪ�˳���������ڣ��Ƴ�����
		CDirector::getInstance()->getRunningScene()->removeChild(this);
	}
}

void CShop::render()
{
	cout << "�̵���Ⱦ" << endl;
}

CShop* CShop::create()
{
	CShop* pRet = new CShop();
	return pRet;
}