// STL.cpp : �������̨Ӧ�ó������ڵ㡣
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

// 	vector<int>::iterator iter = VecNum.begin();//���ص�һ��Ԫ�صĵ�����
// 	cout << *iter << endl;
// 
// 	iter++;
// 	cout << *iter << endl;
//	VecNum.end():����ĩβ�ĵ�����
// 	vector<int>::iterator iter = VecNum.end();
// 	cout << *iter << endl;
// 	for (vector<int>::iterator iter = VecNum.begin(); iter != VecNum.end();)
// 	{
// 		//cout << *iter << endl;
// 		//���Ƴ���++��û�Ƴ�Ҫ++
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
	//��������
	//vector<int>::const_iterator iter = VecNum.cbegin();
	//*iter = 8;

	//VecNum.empty();//�п�
	//VecNum.clear();//���
	//VecNum.insert(VecNum.begin() + 2, 100);
	//cout << VecNum.front() << endl;;
// 	for (int nValue : VecNum)
// 	{
// 		cout << nValue << endl;
// 	}


///map����
// 	map<int, string> mapStar;
// 	mapStar[1] = "С�ɲ���";
// 	mapStar[8] = "ʯԭ����";
// 	mapStar[5] = "ʯԭ����";
// 	mapStar[3] = "��ԫ����";

//	pair<������, ֵ����>(��,ֵ)
//����ֵ
//	mapStar.insert(pair<int, string>(10, "ի�ٷ���"));
//	mapStar[1] = "��ԫ����";

	//���ݷ���
//	cout << mapStar[10] << endl;//����ȫ���������ڵ�ʮ��������map�����
//	cout << mapStar.at(10) << endl;//10�������Ӧ�����ݣ������ڻᱨ��

//����--ͨ������������
// 	map<int, string>::iterator iter = mapStar.begin();//map������һ����������������������
// 	cout << "key:" << iter->first << endl;
// 	cout << "value:" << iter->second << endl;
//	iter++;
// 	cout << "key:" << iter->first << endl;//�Ƶ���һ����3������8��û��˳�����
// 	cout << "value:" << iter->second << endl;
//�������
// 	for (map<int, string>::iterator iter = mapStar.begin(); iter != mapStar.end(); ++iter)
// 	{
// 		cout << iter->first << ":" << iter->second << endl;
// 	}
//��8��Ӧ�ĵ�����
//find:����ҵ��᷵��8��Ӧ�ĵ����������û�ҵ�����mapStar.end()���������
// 	map<int, string>::iterator iter = mapStar.find(8);
// 	if (iter != mapStar.end())
// 	{
// 		cout << iter->first << ":" << iter->second << endl;
// 	}

//	mapStar.cbegin();//��������������ͨ����������������
// 	mapStar.clear();//���
// 	mapStar.size();//�ܸ���

//�Ƴ�
// 	for (map<int, string>::iterator iter = mapStar.begin(); iter != mapStar.end();)
// 	{
// 		if (iter->second == "ʯԭ����")
// 		{
// 			iter = mapStar.erase(iter);//ɾ����᷵����һ�������������Բ���ֱ��++���򷴷����ɾ����--��
// 		}
// 		else
// 		{
// 			++iter;
// 		}
// 	}
//��ȡ��ǰ����
//	cout<<mapStar.size()<<endl;

//list�б�

//��ʽ�ṹ�ڴ治��������ʽ�洢�ṹ����ɾЧ�ʸߣ�����Ч�ʵ�
//�����vector�������ģ�˳��洢�ṹ�������෴
	list<int> listNum;
	//������ĩβѹ������
	listNum.push_back(2);
	listNum.push_back(3);
	listNum.push_back(4);
	listNum.push_back(5);
	listNum.push_back(6);
	listNum.push_back(6);
	listNum.push_back(7);

	//�������һ����7û��
	listNum.pop_back();
	//������һ����2û��
	listNum.pop_front();
	//���
	listNum.clear();
	//��ȡlist�����һ��������
	listNum.begin();
	//��������
	listNum.cbegin();
	//ȡ�����һ��Ԫ��
	cout << listNum.back() << endl;
	//ȡ��һ��Ԫ��
	cout << listNum.front() << endl;;

	listNum.empty();
	listNum.size();
	//ͨ������������
	//�Ƴ�
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
	//�������
	for (list<int>::iterator iter = listNum.begin(); iter != listNum.end(); ++iter)
	{
		cout << *iter << endl;
	}

	system("pause");
	return 0;
}

