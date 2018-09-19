#include "ScoreBoard.h"


CScoreBoard::CScoreBoard()
{
	size = 0;
}

//Nhập scoreboard vào từ file
bool CScoreBoard::Input()
{
	ifstream f("ScoreBoard.txt");
	if (f.fail())
		return false;

	f >> size;
	for (int i = 0; i < size; i++)
	{
		f >> score[i];
		getline(f, name[i]);
	}

	f.close();
	return true;
}

//Xuất scoreboard ra file
void CScoreBoard::Output()
{
	ofstream f("ScoreBoard.txt");
	f << size << endl;
	for (int i = 0; i < size; i++)
	{
		f << score[i] << " " << name[i] << endl;
	}
	f.close();
}
long CScoreBoard::GetBestScore()
{
	long max = 0;
	for (int i = 0; i < size; i++)
	{
		if (score[i] > max)
			max = score[i];
	}
	return max;
}

//Thêm player mới
void CScoreBoard::AddNewUser(string _name, long _score)
{
	for (int i = 0; i < size; i++)
	{
		//Nếu đã tồn tại thì thì xét điểm số
		if (_name == name[i])
		{
			if(_score > score[i])
			{
				score[i] = _score;
				DescendingScore();	//Sắp xếp lại
			}
			return;
		}
	}

	//Nếu chưa tồn tại
	if (size < 10)	//chỉ lưu top 10
	{
		name[size] = _name;
		score[size] = _score;
		size++;
	}
	else	//Nếu đã có 10 người dùng
	{
		//Tìm vị trí có score bé nhất để thêm vào
		int pos = 0;	//Lưu vị trí điểm thấp nhất
		long min = score[0];
		for (int i = 1; i < 10; i++)
		{
			if (score[i] < min)
			{
				pos = i;
			}
		}

		if (score[pos] < _score)
		{
			//thêm vào tại vị trí pos
			score[pos] = _score;
			name[pos] = _name;
		}
	}
	DescendingScore();	//Sắp xếp lại
}

//Sắp xếp điểm giảm dần
void CScoreBoard::DescendingScore()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (score[i] < score[j])
			{
				Swap(score[i], score[j]);
				Swap(name[i], name[j]);
			}
		}
	}
}

//Lấy giá trị của Scoreboard
void CScoreBoard::GetScoreBoard(int &_size, string *_name, long *_score)
{
	_size = size;
	for (int i = 0; i < size; i++)
	{
		_name[i] = name[i];
		_score[i] = score[i];
	}
}