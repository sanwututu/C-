// 2020.9.30.1(��̬��Ա).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>

using namespace std;

//int nCount = 0;
//class Student{
//public:
//	Student(){
//		nCount++;
//	}
//	int getID(){
//		return nID;
//	}
//	//��̬��Ա����
//	static int getCount(){
//		int id = getID();
//		return id;
//	}
//// 	int getCount(){
//// 		return nCount;
//// 	}
//
//private:
//	//��Ա����
//	int nID;
//	//int nCount;//ѧ�����ڰ༶������
//	//��̬��Ա����:�����࣬�������ڶ���ģ��������ж��󶼿��Թ���ñ���
//	//��̬��Ա�����ķ���:1/����.��̬��Ա��2��ͨ������������
//	static int nCount;//ѧ�����ڰ༶������
//	string strName;
//};

//��ͨ��Ա�����ܷ��ʾ�̬��Ա�����𣿿���
//��̬��Ա�����ܷ��ʷǾ�̬��Ա������ ������
//��̬��Ա�����ܷ��ʷǾ�̬��Ա�����𣿲�����

//int Student::nCount = 0;


class CGameMgr
{
public:
	~CGameMgr(){}

	static CGameMgr* getInstance(){
		//����ǵ�һ�ε��ã�Ҫ����һ������
		//����ǵ�2�����ϵ��ã����ص�һ�δ������Ǹ�����
		if (!m_spInstance)
		{
			m_spInstance = new CGameMgr();
		}
		//����ָ��
		return m_spInstance;
	}

	CGameMgr(){}
private:
	static CGameMgr* m_spInstance;
};
CGameMgr* CGameMgr::m_spInstance = nullptr;
//����
int _tmain(int argc, _TCHAR* argv[])
{
	CGameMgr* pGameMgr = CGameMgr::getInstance();
	CGameMgr* pGameMgr1 = CGameMgr::getInstance();
	CGameMgr* pGameMgr2 = CGameMgr::getInstance();
	cout << pGameMgr << endl;//��ֵһ������ͬһ����ַ
	cout << pGameMgr1 << endl;//��ֵһ������ͬһ����ַ
	cout << pGameMgr2 << endl;//��ֵһ������ͬһ����ַ

//	cout << Student::getCount() << endl;
// 	Student* pStudent = new Student();
//	pStudent->getCount();
// 	cout << pStudent->getCount() << endl;
// 	if (pStudent)
// 	{
// 		delete pStudent;
// 		pStudent = nullptr;
// 	}
//	cout << Student::nCount << endl;
	//cout << Student::nCount << endl;
	//Student stu1;
	//Student stu2;
	//cout << Student::nCount << endl;
//  	Student stu1;
// 	stu1.nCount;
// 	stu1.nCount++;
// 	Student stu2;
// 	stu2.nCount = stu1.nCount++;
	system("pause");
	return 0;
}

