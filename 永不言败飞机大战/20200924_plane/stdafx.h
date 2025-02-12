// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
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
// TODO:  在此处引用程序需要的其他头文件
