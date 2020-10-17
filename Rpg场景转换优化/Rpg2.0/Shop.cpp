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
		//返回上一个显示窗口，只需要拿到当前场景，把他孩子（当前要退出的这个窗口）移除即可
		CDirector::getInstance()->getRunningScene()->removeChild(this);
	}
}

void CShop::render()
{
	cout << "商店渲染" << endl;
}

CShop* CShop::create()
{
	CShop* pRet = new CShop();
	return pRet;
}