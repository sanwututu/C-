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

using namespace std;
#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code)&0x8000?1:0)



// TODO:  在此处引用程序需要的其他头文件
