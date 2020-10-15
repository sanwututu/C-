//虚函数.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <windows.h>
#include <iostream>

using namespace std;

//基类
class CA
{
public:
	CA();
	virtual ~CA();
	virtual void print();
private:

};

CA::CA()
{
	cout << "父类的构造函数" << endl;
}

CA::~CA()
{
	cout << "父类类的析构函数" << endl;
}

void CA::print()
{
	cout << "基类A的打印函数" << endl;
}

//派生类继承于A
class CB : public CA
{
public:
	CB();
	~CB();
	//重写父亲的print函数，这里的print也是虚函数。
	virtual void print();//这里的virtual可以不写，因为父亲是虚函数，所以这里print不写也还是虚函数。
private:

};

CB::CB()
{
	cout << "派生类的构造函数" << endl;
}

CB::~CB()
{
	cout << "派生类的析构函数" << endl;
}

void CB::print()
{
	cout << "派生类B的打印函数" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//CA* pA = new CA();
	//pA->print();
	//CB* pB = new CB();
	//pB->print();

	////父亲指针是可以存储孩子对象的内存。
	//CA* pA1 = (CA*)pB;
	//pA1->print();
	//指针是什么类型在调用函数的时候，就调用相应类型对应的函数。
	//应该是内存是谁的就调用谁的函数。 不管指针类型是A还是B，都是输出B的print
	//解决办法：把父类的函数定义成虚函数。 virtual +正常函数定义---virtual void print();。


	//在new一个派生类对象的时候，会先去调用基类的构造函数再调用派生类的构造函数。
	CB* pB = new CB();
	//在释放内存的时候，会先调用派生类的析构函数，再去调用基类的析构函数。
	//delete pB;

	CA* pA = (CA*)pB;
	//如果是基类指针存储派生类对象内存，那么在释放内存的时候，只会调用父类的析构函数，意味着派生类的析构没有调用，内存释放不完全，内存泄漏。
	//解决办法：把父类的析构函数设置为虚析构函数。

	//为什么要设置虚析构函数?
	/*答：如果是基类指针存储派生类对象内存，那么在释放内存的时候，
	只会调用父类的析构函数，意味着派生类的析构没有调用，内存释放不完全，内存泄漏 */
	delete pA;
	system("pause");
	return 0;
}

