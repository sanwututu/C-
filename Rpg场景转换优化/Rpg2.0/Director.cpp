#include "stdafx.h"
#include "Director.h"

//管理场景变化的类
//初始化赋值为空
CDirector* CDirector::m_spInstance = nullptr;
CDirector::CDirector()
:m_pCurScene(nullptr)
{
}
CDirector::~CDirector()
{
}
//创建/返回指针
CDirector* CDirector::getInstance()
{
	if (!m_spInstance)
	{
		m_spInstance = new CDirector();
	}
	return m_spInstance;
}
//运行函数
void CDirector::run(){
	while (true){
		system("cls");
		//this指代当前类对象,到时候外部哪个对象调用了这个run函数，那么this就是那个对象。
		this->update();
		this->render();
	}
}
void CDirector::update(){
	m_pCurScene->update();
}
void CDirector::render(){
	m_pCurScene->render();
}
void CDirector::replaceScene(CScene* pScene)
{
	m_pCurScene = pScene;
}

