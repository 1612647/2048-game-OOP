#include "Grid.h"

#define block_width 7
#define block_height 3
Grid::Grid() {
	int _x = x = x_grid;
	int _y = y = y_grid;

	int random[2];	//Tạo 2 ô có giá trị khi bắt đầu game;
	srand((unsigned int)time(NULL));
	random[0] = rand() % 16;
	do {
		random[1] = rand() % 16;
	} while (random[0] == random[1]);

	for (int i = 0; i < 16; i++)
	{
		_x = x + i % 4 * block_width;	//độ rộng của 1 ô là 7
		_y = y + i / 4 * block_height;	//chiều cao của 1 ô là 3 dòng
		if (i == random[0] || i == random[1])
		{
			int _value = (rand() % 2) * 2 + 2;	//random giá trị 2 hoặc 4
			Block b(_x, _y, _value);
			grid[i / 4][i % 4] = b;
		}
		else {
			Block b(_x, _y);
			grid[i / 4][i % 4] = b;
		}
	}
}
void Grid::Show()
{
	for (int i = 0; i < 16; i++)
		grid[i / 4][i % 4].Show();
}

//Trả về kết quả có move được không hay giữ nguyên
bool Grid::MoveUp(int _i, int _j)	//đưa ô lên ô trống trên cùng
{
	int pos = -1;
	for (int i = _i - 1; i >= 0; i--)	//Tìm vị trí ô trống trên cùng
	{
		if (grid[i][_j].IsEmpty())
			pos = i;
		else break;
	}
	if (pos != -1)
	{
		grid[_i][_j].Move(grid[pos][_j]);
		return true;
	}
	return false;
}

//Hàm trượt lên
//Return true nếu thành công, false nếu giữ nguyên
bool Grid::SlideUp(long &score)
{
	score = 0;

	bool ans = false;
	//Move
	for (int j = 0; j < 4; j++)		//Duyệt từng cột
	{
		for (int i = 1; i < 4; i++)		//Duyệt từng dòng
		{
			if (!grid[i][j].IsEmpty())
			{
				bool tmp = MoveUp(i, j);
				ans = (ans || tmp);
			}
		}
	}


	//Merge
	for (int j = 0; j < 4; j++)		//Duyệt từng cột
	{
		for (int i = 1; i < 4; i++)		//Duyệt từng dòng
		{
			if(grid[i - 1][j].IsEmpty() == false)
				if (grid[i][j] == grid[i - 1][j])	//Nếu là 2 ô liên tiếp giống nhau thì gộp thành 1 ô và nhảy 2 ô
				{
					grid[i - 1][j].Merge(grid[i][j]);

					score += grid[i - 1][j].GetValue();	
					ans = true;
				}

		}
	}

	//Move
	for (int j = 0; j < 4; j++)		//Duyệt từng cột
	{
		for (int i = 1; i < 4; i++)		//Duyệt từng dòng
		{
			if (!grid[i][j].IsEmpty())
			{
				bool tmp = MoveUp(i, j);
				ans = (ans || tmp);
			}
		}
	}


	return ans;
}


//Trả về có move được hay không
bool Grid::MoveDown(int _i, int _j)	//đưa ô xuống ô trống dưới cùng
{
	int pos = -1;
	for (int i = _i+ 1; i < 4; i++)
	{
		if (grid[i][_j].IsEmpty())
			pos = i;
		else break;
	}
	if (pos != -1)
	{
		grid[_i][_j].Move(grid[pos][_j]);
		return true;
	}
	return false;
}

//Hàm trượt xuống
//Trả về có thay đổi hay không
bool Grid::SlideDown(long &score)
{
	score = 0;

	bool ans = false;
	//Move
	for (int j = 0; j < 4; j++)		//Duyệt từng cột
	{
		for (int i = 2; i >= 0; i--)		//Duyệt từng dòng
		{
			if (!grid[i][j].IsEmpty())
			{
				bool tmp = MoveDown(i, j);
				ans = (ans || tmp);
			}
		}
	}


	//Merge
	for (int j = 0; j < 4; j++)		//Duyệt từng cột
	{
		for (int i = 2; i >= 0; i--)		//Duyệt từng dòng
		{
			if (grid[i + 1][j].IsEmpty() == false)
				if (grid[i][j] == grid[i + 1][j])	//Nếu là 2 ô liên tiếp giống nhau thì gộp thành 1 ô và nhảy 2 ô
				{
					grid[i + 1][j].Merge(grid[i][j]);

					score += grid[i +1 ][j].GetValue();
					ans = true;
				}

		}
	}

	//Move lần 2
	for (int j = 0; j < 4; j++)		//Duyệt từng cột
	{
		for (int i = 2; i >= 0; i--)		//Duyệt từng dòng
		{
			if (!grid[i][j].IsEmpty())
			{
				 bool tmp = MoveDown(i, j);
				 ans = (ans || tmp);
			}
		}
	}

	return ans;
}


bool Grid::MoveLeft(int _i, int _j)	//đưa ô sang ô trống bên trái cùng
{
	int pos = -1;
	for (int j = _j - 1; j >= 0; j--)	//Tìm vị trí ô trống trái cùng
	{
		if (grid[_i][j].IsEmpty())
			pos = j;
		else break;
	}
	if (pos != -1)
	{
		grid[_i][_j].Move(grid[_i][pos]);
		return true;
	}
	return false;
}

//Hàm trượt qua trái
bool Grid::SlideLeft(long &score)
{
	score = 0;

	bool ans = false;
	//Move
	for (int i = 0; i < 4; i++)		//Duyệt từng dòng
	{
		for (int j = 1; j < 4; j++)		//Duyệt từng cột
		{
			if (!grid[i][j].IsEmpty())
			{
				bool tmp = MoveLeft(i, j);
				ans = (ans || tmp);
			}
		}
	}


	//Merge
	for (int i = 0; i < 4; i++)		//Duyệt từng dòng
	{
		for (int j = 1; j < 4; j++)		//Duyệt từng cột
		{
			if (grid[i][j - 1].IsEmpty() == false)
				if (grid[i][j] == grid[i][j - 1])	//Nếu là 2 ô liên tiếp giống nhau thì gộp thành 1 ô và nhảy 2 ô
				{
					grid[i][j - 1].Merge(grid[i][j]);

					score += grid[i][j - 1].GetValue();
					ans = true;
				}

		}
	}

	//Move lần nữa
	for (int i = 0; i < 4; i++)		//Duyệt từng dòng
	{
		for (int j = 1; j < 4; j++)		//Duyệt từng cột
		{
			if (!grid[i][j].IsEmpty())
			{
				bool tmp = MoveLeft(i, j);
				ans = (ans || tmp);
			}
		}
	}

	return ans;
}


bool Grid::MoveRight(int _i, int _j)	//đưa ô sang ô trống bên phải cùng
{
	int pos = -1;
	for (int j = _j + 1; j < 4; j++)
	{
		if (grid[_i][j].IsEmpty())
			pos = j;
		else break;
	}
	if (pos != -1)
	{
		grid[_i][_j].Move(grid[_i][pos]);
		return true;
	}
	return false;
}

//Hàm trượt qua phải
bool Grid::SlideRight(long &score)
{
	score = 0;

	bool ans = false;
	//Move
	for (int i = 0; i < 4; i++)		//Duyệt từng dòng
	{
		for (int j = 2; j >= 0; j--)		//Duyệt từng cột
		{
			if (!grid[i][j].IsEmpty())
			{
				bool tmp = MoveRight(i, j);
				ans = (ans || tmp);
			}
		}
	}


	//Merge
	for (int i = 0; i < 4; i++)		//Duyệt từng  dòng
	{
		for (int j = 2; j >= 0; j--)		//Duyệt từng cột
		{
			if (grid[i][j + 1].IsEmpty() == false)
				if (grid[i][j] == grid[i][j + 1])	//Nếu là 2 ô liên tiếp giống nhau thì gộp thành 1 ô và nhảy 2 ô
				{
					grid[i][j + 1].Merge(grid[i][j]);

					score += grid[i][j + 1].GetValue();
					ans = true;
				}
		}
	}

	//Move lần 2
	for (int i = 0; i < 4; i++)		//Duyệt từng dòng
	{
		for (int j = 2; j >= 0; j--)		//Duyệt từng cột
		{
			if (!grid[i][j].IsEmpty())
			{
				bool tmp = MoveRight(i, j);
				ans = (ans || tmp);
			}
		}
	}

	return ans;
}

//Kiểm tra các ô đã được lấp đầy
bool Grid::IsFull()
{
	for (int i = 0; i < 16; i++)
	{
		if (grid[i / 4][i % 4].IsEmpty())
			return false;
	}
	return true;
}

//Thua
bool Grid::IsOver()
{
	if(!IsFull())
	{
		return false;
	}
	else
	{
		//Nếu các ô đã được lấp đầy thì tìm xem có 2 ô nào liên tiếp bằng nhau không
		
		//Tìm theo chiều dọc
		for (int j = 0; j < 4; j++)		//Duyệt cột
		{
			for (int i = 0; i < 4 - 1; i++)	//Duyệt dòng
			{
				if (grid[i][j] == grid[i + 1][j])
				{
					return false;
				}
			}
		}
		//Tìm theo chiều ngang
		for (int i = 0; i < 4; i++)		//Duyệt dòng
		{
			for (int j = 0; j < 4 - 1; j++)	//Duyệt cột
			{
				if (grid[i][j] == grid[i][j + 1])
				{
					return false;
				}
			}
		}
	}
	return true;
}

//Thắng
bool Grid::IsWin()
{
	//Thắng nếu xuất hiện ô 2048
	for (int i = 0; i < 16; i++)
	{
		if (grid[i / 4][i % 4].GetValue() == 2048)
			return true;
	}
	return false;
}

//Tạo ô mới có giá trị ngẫu nhiên ở vị trí ngẫu nhiên
void Grid::AddNewBlock()
{
	srand((unsigned int)time(NULL));
	int _value = (rand() % 2) * 2 + 2;	//random 2 or 4
	int pos;
	do
	{
		pos = rand() % 16;
	} while (grid[pos / 4][pos % 4].IsEmpty() == false);

	grid[pos / 4][pos % 4].SetValue(_value);
}

//Lưu mảng 2 chiều vào file f
void Grid::Save(ofstream& f)
{
	for (int i = 0; i < 16; i++)
	{
		f << grid[i / 4][i % 4].GetValue() << " ";
	}
	f << endl;
}

//load mảng 2 chiều từ file f
void Grid::Load(long &score, string& user, ifstream &f)
{
	int _value;
	for (int i = 0; i < 16; i++)
	{
		f >> _value;
		grid[i / 4][i % 4].SetValue(_value);
	}

	getline(f, user); getline(f, user);
	f >> score;
}
