// pointer(指针).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>

using namespace std;
//void createMemory();
//int* createMemory();

void Swap(int* pNum1, int* pNum2);

// struct SData
// {
// 	int nRow;
// 	int nCol;
// };
int _tmain(int argc, _TCHAR* argv[])
{
	//指针:用于存放内存地址到
	//指针类型 + *+指针名称 = 地址;
	//C++11:2011 VS2012以上才支持
	//int* pNum = nullptr;
	//int nNum = 5;
	////&:取地址符
	//int* pNum = &nNum;

	//可以通过指针来改变它所指向到地址到值(改变内存中到数据):*指针名 = 值;
	//*pNum = 6;

	//获取指针所指向到内存地址到值:*指针名称
	//cout << "nNum:" << nNum << endl;
	//cout << "pNum的值:" << *pNum << endl;

	//pNum:pNum指针所存到地址

// 	cout << &nNum << endl;
// 	cout << pNum << endl;
// 	cout << &pNum << endl;

	//指针指向的地址可以改变
// 	int nNum2 = 8;
// 	pNum = &nNum2;
// 
// 	*pNum = 10;

	//命名规范:加前缀p(pointer)

	//所有到内存都要经过申请才能使用
	//操作指针之前一定要保证它所指向到内存地址是可用到
	//申请内存:new 类型
// 	int* pNum = new int;
// 	*pNum = 5;
// 	if (pNum)
// 	{
// 		delete pNum;
// 		pNum = nullptr;
// 	}
// 	if (pNum)
// 	{
// 		delete pNum;
// 		pNum = nullptr;
// 	}
	//delete pNum;
	//new出来到内存一定要记得delete



	//int* pNum = new int[5];
	//*pNum = 5;
	//*(pNum + 1) = 6;
	////cout << *pNum << endl;

	//for (int i = 0; i < 5; i++)
	//{
	//	cout << *(pNum + i) << endl;
	//}

	//操作指针之前一定要保证它所指向到内存地址是可用的
// 	int* pNum = createMemory();
// 	*pNum = 8;//崩溃

// 	SData* pData = new SData();
// 	SData data;
// 	data.nRow = 5;
// 	data.nCol = 6;
// 	pData->nRow = 5;
// 	pData->nCol = 6;


	int nNum1 = 5;
	int nNum2 = 6;
	Swap(&nNum1, &nNum2);
	cout << "nNum1 = " << nNum1 << endl;
	cout << "nNum2 = " << nNum2 << endl;
	system("pause");
	return 0;
}

//void createMemory()
//{
//	if (true)
//	{
//		//块作用域:从定义处开始到它所在到{}结束
//		int nNum = 5;
//	}
//	cout << "aaa" << endl;
//	//int* pNum = new int;
//}

//int* createMemory()
//{
//	int nNum = 5;
//	return &nNum;
//}

//地址传递
void Swap(int* pNum1, int* pNum2)
{//值传递
	// int nTemp = *pNum1;
	// *pNum1 = *pNum2;
	// *pNum2 = nTemp;

//交换地址
	int* pTemp = pNum1;
	pNum1 = pNum2;
	pNum2 = pTemp;
	cout << "*pNum1 = " << *pNum1 << endl;
	cout << "*pNum2 = " << *pNum2 << endl;
}