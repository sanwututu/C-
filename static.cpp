// 2020.9.30.1(静态成员).cpp : 定义控制台应用程序的入口点。
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
//	//静态成员函数
//	static int getCount(){
//		int id = getID();
//		return id;
//	}
//// 	int getCount(){
//// 		return nCount;
//// 	}
//
//private:
//	//成员变量
//	int nID;
//	//int nCount;//学生所在班级总人数
//	//静态成员变量:属于类，并不属于对象的，但是所有对象都可以共享该变量
//	//静态成员变量的访问:1/对象.静态成员名2、通过类名来访问
//	static int nCount;//学生所在班级总人数
//	string strName;
//};

//普通成员函数能访问静态成员变量吗？可以
//静态成员函数能访问非静态成员变量吗？ 不可以
//静态成员函数能访问非静态成员函数吗？不可以

//int Student::nCount = 0;


class CGameMgr
{
public:
	~CGameMgr(){}

	static CGameMgr* getInstance(){
		//如果是第一次调用，要创建一个对象
		//如果是第2次以上调用，返回第一次创建的那个对象
		if (!m_spInstance)
		{
			m_spInstance = new CGameMgr();
		}
		//返回指针
		return m_spInstance;
	}

	CGameMgr(){}
private:
	static CGameMgr* m_spInstance;
};
CGameMgr* CGameMgr::m_spInstance = nullptr;
//单例
int _tmain(int argc, _TCHAR* argv[])
{
	CGameMgr* pGameMgr = CGameMgr::getInstance();
	CGameMgr* pGameMgr1 = CGameMgr::getInstance();
	CGameMgr* pGameMgr2 = CGameMgr::getInstance();
	cout << pGameMgr << endl;//数值一样，是同一个地址
	cout << pGameMgr1 << endl;//数值一样，是同一个地址
	cout << pGameMgr2 << endl;//数值一样，是同一个地址

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

