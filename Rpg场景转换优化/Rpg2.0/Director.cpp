#include "stdafx.h"
#include "Director.h"

//�������仯����
//��ʼ����ֵΪ��
CDirector* CDirector::m_spInstance = nullptr;
CDirector::CDirector()
:m_pCurScene(nullptr)
{
}
CDirector::~CDirector()
{
}
//����/����ָ��
CDirector* CDirector::getInstance()
{
	if (!m_spInstance)
	{
		m_spInstance = new CDirector();
	}
	return m_spInstance;
}
//���к���
void CDirector::run(){
	while (true){
		system("cls");
		//thisָ����ǰ�����,��ʱ���ⲿ�ĸ�������������run��������ôthis�����Ǹ�����
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

