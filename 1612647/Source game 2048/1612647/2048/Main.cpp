#include "GameUI.h"
#include "Game.h"
#include "MyGraphics.h"

int main()
{
	setFontSize(18);
	ResizeConsole(max_width, max_height);
	GameUI* _2048 = new Game;
	_2048->MainMenu();

	delete _2048;
	
	return 0;
}
