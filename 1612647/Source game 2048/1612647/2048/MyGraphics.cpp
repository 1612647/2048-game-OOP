#include "MyGraphics.h"


void ResizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, true);
}

void TextColor(int x)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}
void GoToXY(int x, int y)
{
	HANDLE Output;
	COORD Pos = { x - 1, y - 1 };
	Output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Output, Pos);
}
void ClearScreen()
{
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Pos;
	Pos.X = Pos.Y = 0;
	SetConsoleCursorPosition(Out, Pos);
}
//Hàm in ra chuỗi str với màu và tại vị trí cho trước
void Print(int _x, int _y, int color, string str)
{
	GoToXY(_x, _y);
	TextColor(color);
	cout << str;
	TextColor(7);	//Set lại màu mặc định
}

//Thay đổi kích thước chữ
void setFontSize(int FontSize)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}