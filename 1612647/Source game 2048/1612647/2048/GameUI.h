#ifndef _GAMEUI_H
#define _GAMEUI_H
#define max_width 400
#define max_height 700
#define block_width 7
#define block_height 3
#define x_grid 10
#define y_grid 14
class GameUI {
public:
	virtual void Show() = 0;
	virtual void Play() = 0;
	virtual bool Load() = 0;
	virtual void Save() = 0;
	virtual void MainMenu() = 0;
	virtual void ShowLogo() = 0;
	virtual void Win() = 0;
	virtual void GameOver() = 0;
	virtual void ScoreBoard() = 0;
	virtual void InputUserName() = 0;
	virtual void PauseMenu() = 0;
	virtual void Undo() = 0;
};

#endif