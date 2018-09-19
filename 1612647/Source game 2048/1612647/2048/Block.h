#ifndef _BLOCK_H
#define _BLOCK_H
#include "MyGraphics.h"
#include "GameUI.h"
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;
class Block {
private:
	int x, y;
	long value;
public:
	Block();
	Block(int _x, int _y);
	Block(int _x, int _y, long _value);
	bool operator==(Block b);
	int GetX();
	int GetY();
	long GetValue();
	void SetValue(long _value);
	bool IsEmpty();
	void Show();
	void SetEmpty();
	void Move(Block &dest);
	void Merge(Block &join);
};
#endif