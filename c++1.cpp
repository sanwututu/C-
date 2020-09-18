// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//10.2.50.24

#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;
#define KEY_DOWN(vk_code)(GetAsyncKeyState(vk_code)&0x8000?1:0)
int _tmain(int argc, _TCHAR* argv[])
{
	//1、1+1+2+1+2+3+1+2+3+4...20
	//int i = 1;
	//int nNum = 0;
	//int nSum = 0;
	//
	//	while (i <= 20)
	//	{
	//		nNum += i;
	//		nSum += nNum;		
	//		i++;
	//	}
	//cout << nSum<<endl;
	//system("pause");

	//2、10!
	/*int i = 1;
	int nSum = 1;
	while (i <= 10)
	{
		nSum *= i;
		i++;
		
	}
	cout << nSum<<endl;
	system("pause");*/
	//3、1!+2!+3!...10!
	//int i = 1;
	//int nNum = 1;
	//int nSum = 0;
	//while (i <= 10)
	//{
	//	nNum *= i;
	//	nSum += nNum;

	//	i++;

	//}
	//cout << nSum << endl;//4037913
	//4.输入一个五位数，输出它反转后的结果
	/*int x;
	cin >> x;
	if (x < 10000 && x>99999){
		cout << "不是五位数！";
	}
	else{
		int a1 = x / 10000;
		int a2 = x % 10000 / 1000;
		int a3 = x % 1000 / 100;
		int a4 = x % 100 / 10;
		int a5 = x % 10;

		cout << a5*10000+a4*1000+a3*100+a2*10+a1;
	}*/
	
	//5.输出游戏菜单界面
	
	int nKey = 0;
	while (true){
		if (KEY_DOWN(VK_DOWN)){
			nKey++;
			if (nKey > 2){
				nKey = 0;
			}
		}
		if (KEY_DOWN(VK_UP)){
			nKey--;
			if (nKey <0){
				nKey = 2;
			}
		}
		cout << "■■■■■■■■■■■■■■■■■■"<<endl;
		cout << "■■■■■■■■■■■■■■■■■■"<<endl;
		if (nKey == 0){
			cout << "■■■■■  ->游戏开始  ■■■■■■" << endl;
			cout << "■■■■■    游戏设置  ■■■■■■" << endl;
			cout << "■■■■■    游戏结束  ■■■■■■" << endl;
		}
		else if (nKey == 1){
			cout << "■■■■■    游戏开始  ■■■■■■" << endl;
			cout << "■■■■■  ->游戏设置  ■■■■■■" << endl;
			cout << "■■■■■    游戏结束  ■■■■■■" << endl;
		}
		else{
			cout << "■■■■■    游戏开始  ■■■■■■" << endl;
			cout << "■■■■■    游戏设置  ■■■■■■" << endl;
			cout << "■■■■■  ->游戏结束  ■■■■■■" << endl;
		}
		cout << "■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■" << endl;
		if (nKey == 0){
			cout << "游戏开始" << endl;
		}
		else if (nKey == 1){
			cout << "游戏设置" << endl;
		}
		else{
			
			cout << "游戏结束" << endl;
		}
		system("cls");//清屏
	}

	system("pause");
	return 0;
}

