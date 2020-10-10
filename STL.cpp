// STL.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
// 	vector<int> VecNum;
// 	VecNum.push_back(1);
// 	VecNum.push_back(2);
// 	VecNum.push_back(3);
// 	VecNum.push_back(3);
// 	VecNum.push_back(5);

// 	for (int i = 0; i < VecNum.size(); i++)
// 	{
// 		cout << VecNum[i] << endl;
// 	}

// 	for (int nValue:VecNum)
// 	{
// 		cout << nValue << endl;
// 	}

// 	vector<int>::iterator iter = VecNum.begin();//返回第一个元素的迭代器
// 	cout << *iter << endl;
// 
// 	iter++;
// 	cout << *iter << endl;
//	VecNum.end():容器末尾的迭代器
// 	vector<int>::iterator iter = VecNum.end();
// 	cout << *iter << endl;
// 	for (vector<int>::iterator iter = VecNum.begin(); iter != VecNum.end();)
// 	{
// 		//cout << *iter << endl;
// 		//有移除不++；没移除要++
// 		if (3 == *iter)
// 		{
// 			iter = VecNum.erase(iter);
// 		}
// 		else
// 		{
// 			++iter;
// 		}
// 	}



//	cout << VecNum.at(2) << endl;

//	cout << VecNum.back() << endl;


	//vector<int>::iterator iter = VecNum.begin();
	//常迭代器
	//vector<int>::const_iterator iter = VecNum.cbegin();
	//*iter = 8;

	//VecNum.empty();//判空
	//VecNum.clear();//清空
	//VecNum.insert(VecNum.begin() + 2, 100);
	//cout << VecNum.front() << endl;;
// 	for (int nValue : VecNum)
// 	{
// 		cout << nValue << endl;
// 	}


///map容器
// 	map<int, string> mapStar;
// 	mapStar[1] = "小松菜奈";
// 	mapStar[8] = "石原里美";
// 	mapStar[5] = "石原里美";
// 	mapStar[3] = "新垣结衣";

//	pair<键类型, 值类型>(键,值)
//插入值
//	mapStar.insert(pair<int, string>(10, "斋藤飞鸟"));
//	mapStar[1] = "新垣结衣";

	//数据访问
//	cout << mapStar[10] << endl;//不安全，若不存在第十个，会往map里插入
//	cout << mapStar.at(10) << endl;//10这个键对应的数据，不存在会报错。

//遍历--通过迭代器遍历
// 	map<int, string>::iterator iter = mapStar.begin();//map容器第一个迭代器，包含两个数据
// 	cout << "key:" << iter->first << endl;
// 	cout << "value:" << iter->second << endl;
//	iter++;
// 	cout << "key:" << iter->first << endl;//移到下一个是3，不是8，没有顺序可言
// 	cout << "value:" << iter->second << endl;
//遍历输出
// 	for (map<int, string>::iterator iter = mapStar.begin(); iter != mapStar.end(); ++iter)
// 	{
// 		cout << iter->first << ":" << iter->second << endl;
// 	}
//找8对应的迭代器
//find:如果找到会返回8对应的迭代器，如果没找到返回mapStar.end()这个迭代器
// 	map<int, string>::iterator iter = mapStar.find(8);
// 	if (iter != mapStar.end())
// 	{
// 		cout << iter->first << ":" << iter->second << endl;
// 	}

//	mapStar.cbegin();//常迭代器，不可通过常迭代器改内容
// 	mapStar.clear();//清除
// 	mapStar.size();//总个数

//移除
// 	for (map<int, string>::iterator iter = mapStar.begin(); iter != mapStar.end();)
// 	{
// 		if (iter->second == "石原里美")
// 		{
// 			iter = mapStar.erase(iter);//删除后会返回下一个迭代器，所以不能直接++，或反方向可删（用--）
// 		}
// 		else
// 		{
// 			++iter;
// 		}
// 	}
//获取当前个数
//	cout<<mapStar.size()<<endl;

//list列表

//链式结构内存不连续，链式存储结构，增删效率高，查找效率低
//数组和vector是连续的，顺序存储结构，与上相反
	list<int> listNum;
	//往链表末尾压入数据
	listNum.push_back(2);
	listNum.push_back(3);
	listNum.push_back(4);
	listNum.push_back(5);
	listNum.push_back(6);
	listNum.push_back(6);
	listNum.push_back(7);

	//弹出最后一个，7没了
	listNum.pop_back();
	//弹出第一个，2没了
	listNum.pop_front();
	//清空
	listNum.clear();
	//获取list链表第一个迭代器
	listNum.begin();
	//常迭代器
	listNum.cbegin();
	//取到最后一个元素
	cout << listNum.back() << endl;
	//取第一个元素
	cout << listNum.front() << endl;;

	listNum.empty();
	listNum.size();
	//通过迭代器遍历
	//移除
	for (list<int>::iterator iter = listNum.begin(); iter != listNum.end();)
	{
		if (6 == *iter)
		{
			iter = listNum.erase(iter);
		}
		else{
			++iter;
		}
	}
	//遍历输出
	for (list<int>::iterator iter = listNum.begin(); iter != listNum.end(); ++iter)
	{
		cout << *iter << endl;
	}

	system("pause");
	return 0;
}

