#ifndef _SCOREBOARD_H
#define _SCOREBOARD_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

template<class T>
void Swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

class CScoreBoard
{
private:
	string name[10];
	long score[10];
	int size;
public:
	CScoreBoard();
	bool Input();
	void Output();
	long GetBestScore();
	void AddNewUser(string _name, long _score);
	void DescendingScore();
	void GetScoreBoard(int &_size, string *_name, long *_score);
};

#endif