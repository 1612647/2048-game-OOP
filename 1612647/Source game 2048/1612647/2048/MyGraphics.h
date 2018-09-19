#ifndef _MY_GRAPHICS_H
#define _MY_GRAPICS_H
#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;
void ResizeConsole(int width, int height);
void TextColor(int x);
void GoToXY(int x, int y);
void ClearScreen();		//Xoá mang hình
void Print(int _x, int _y, int color, string str);	//Hàm in ra chuỗi str với màu và tại vị trí cho trước
void setFontSize(int FontSize);
#endif

