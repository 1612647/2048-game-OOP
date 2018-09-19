#ifndef _GRID_H
#define _GRID_H
#include "Block.h"
#include <time.h>
#include "GameUI.h"
#include <fstream>
class Grid {
private:
	Block grid[4][4];
	int x, y;
public:
	Grid();
	void Show();

	bool MoveUp(int _i, int _j);	//đưa ô lên ô trống trên cùng
	//Return có dồn ô được hay không
	bool SlideUp(long& score);
	bool MoveDown(int _i, int _j);	//đưa ô xuống ô trống dưới cùng	
	bool SlideDown(long& score);
	bool MoveLeft(int _i, int _j);	//đưa ô sang ô trống bên trái cùng
	bool SlideLeft(long& score);
	bool MoveRight(int _i, int _j);	//đưa ô xuống ô trống dưới cùng
	bool SlideRight(long& score);

	bool IsFull();
	bool IsOver();
	bool IsWin();
	void AddNewBlock();
	void Save(ofstream&);
	void Load(long &score, string &user , ifstream&);
};
#endif