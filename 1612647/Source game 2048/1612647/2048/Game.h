#ifndef _GAME_H
#define _GAME_H
#include "GameUI.h"
#include "Grid.h"
#include "MyGraphics.h"
#include "ScoreBoard.h"
#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;
class Game : public GameUI
{
private:
	Grid grid;
	string user;
	long score;
	bool isUndid, isShowWin; //Kiểm tra Đã undo hay chưa, kiểm tra đã show màn hình chiến thắng hay chưa
	CScoreBoard SB;
	////Time;
public:
	Game();
	void ShowLogo();
	void Win();
	void GameOver();
	void Show();
	void ScoreBoard();
	void InputUserName();
	void MainMenu();
	void PauseMenu();
	void Play();
	void Save();
	bool Load();
	void Undo();
};

#endif