// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include "time.h"

using namespace std;
#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code)&0x8000?1:0)

#define SAFE_DEL(p)	if(p){delete p; p = nullptr;}

enum
{
	E_STATE_MENU,
	E_STATE_ROLE,
	E_STATE_MAP,
};
enum DIR
{
	E_DIR_UP,
	E_DIR_LEFT,
	E_DIR_DOWN,
	E_DIR_RIGHT
};
enum
{
	E_MENU_START,
	E_MENU_SETTING,
	E_MENU_EXIT
};
// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
