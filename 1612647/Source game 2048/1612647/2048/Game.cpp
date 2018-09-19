#include "Game.h"

Game::Game()
{
	score = 0;
	isUndid = false;
	isShowWin = false;
	SB.Input();
}

//Hiển thị logo game
void Game::ShowLogo()
{
	ifstream f("Logo.txt");
	if (f.fail())
	{
		Print(1, 3, 11, " LOGO not found! ");
	}
	
	else
	{
		char x;
		TextColor(11);
		while (!f.eof())
		{
			/*i++;*/
			f.get(x);
			if (x == '\n') /*&& i < max_width/10-1*/
			{
				/*for (int j = i + 1; j < max_width/10-1; j++)
				cout << " ";*/
				/*Sleep(5);*/
			}
			cout << x;

		}
		cout << endl;

		TextColor(7);
		f.close();
	}
}

//Hiển trị màn hình thông báo khi thắng
void Game::Win()
{
	isShowWin = true;
	while (true)
	{
		system("cls");
		ShowLogo();


		Print(12, 28, 78, " ESC ");
		Print(8, 30, 12, " Back to menu ");
		Print(30, 28, 78, " Enter ");
		Print(28, 30, 12, " Continue ");

		ifstream f("WinLogo.txt");
		if (f.fail())
		{
			Print(19, 15, 14, " You Won! \n\n\t");
			Sleep(1000);
		}
		else
		{
			GoToXY(1, 14);
			char x;
			TextColor(14);
			while (!f.eof())
			{
				f.get(x);
				if (x == '\n')
				{
					Sleep(500);
				}
				cout << x;

			}
			cout << endl;

			TextColor(7);
			Sleep(2000);
		}

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			system("cls");
			MainMenu();
			return;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			Play();
			return;
		}
	}
}

//Hiện thị màn hình thông báo game over
void Game::GameOver()
{
	while (true)
	{
		system("cls");
		ShowLogo();
		
		Print(12, 28, 78, " ESC ");
		Print(7, 30, 12, " Back to menu ");
		Print(30, 28, 78, " Enter ");
		Print(29, 30, 12, " New Game ");

		ifstream f("GameOverLogo.txt");
		if (f.fail())
		{
			Print(19, 15, 14, " Game Over! \n\n\t");
			Sleep(1000);
		}
		else {
			GoToXY(1, 14);
			char x;
			TextColor(12);
			while (!f.eof())
			{
				f.get(x);
				if (x == '\n')
				{
					Sleep(500);
				}
				cout << x;

			}
			cout << endl;

			TextColor(7);
			Sleep(1000);
		}

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			system("cls");
			MainMenu();
			return;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			Grid tmp;
			grid = tmp;
			score = 0;
			Play();
			return;
		}
	}
}


//Hiển thị giao diện chính của game
void Game::Show()
{
	ClearScreen();
	ShowLogo();
	Print(10, 9, 14, " HELLO " + user + "!");
	Print(10, 11, 46, " Score: " + to_string(score) + " ");
	Print(25, 11, 46, " Best: " + to_string(SB.GetBestScore()) + " ");

	grid.Show();
	Print(8, 30, 78, " Backspace ");
	Print(10, 32, 12, " Undo ");
	Print(7, 33, 12, " (" + to_string(!isUndid) + " times) ");
	Print(34, 28, 78, " ^ ");
	Print(30, 30, 78, " < ");
	Print(38, 30, 78, " > ");
	Print(34, 32, 78, " v ");
	Print(32, 34, 12, " Move ");
	Print(13, 36, 12, "Press ESC to show menu!");
}

//Hiển thị score board 
void Game::ScoreBoard()
{
	while (true)
	{
		system("cls");
		ShowLogo();
		Print(17, 9, 11, "SCORE BOARD:");

		int _x = 10, _y = 12;

		Print(_x + 2, _y, 13, "Player");
		Print(_x + 22, _y, 13, "Score");

		_y += 2;


		int size;
		string _name[10];
		long _score[10];
		SB.GetScoreBoard(size, _name, _score);

		//In ra score board 
		string rank[10] = { "1st","2nd","3rd","4th","5th","6th","7th","8th","9th","10th" };
		for (int i = 0; i < size; i++)
		{
			Print(_x, _y, 14, rank[i] + ". " + _name[i]);

			TextColor(2);
			GoToXY(_x + 18, _y);
			cout << setw(10) << _score[i];
			_y += 2;

			TextColor(7);
		}

		Print(13, 34, 12, "Press ESC to come back!");
		system("pause>nul");

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			return;
		}
	}
}


//Nhập tên người dùng
void Game::InputUserName()
{
	system("cls");
	ShowLogo();
	Print(8, 15, 12, "Your name: ");
	getline(cin, user);
}

//Hiển thị menu chính
void Game::MainMenu()
{
	ClearScreen();
	ShowLogo();
	int choose = 0;
	while (true)
	{
		system("cls");
		cout << endl;
		ShowLogo();

		TextColor(14);
		GoToXY(17, 14);
		if (choose % 4 == 0)
		{
			cout << ">";
		}
		cout << "  New Game ";

		GoToXY(17, 16);
		if (choose % 4 == 1)
		{
			cout << ">";
		}
		cout << "  Load Game ";

		GoToXY(17, 18);
		if (choose % 4 == 2)
		{
			cout << ">";
		}
		cout << "  Score Board ";

		GoToXY(17, 20);
		if (choose % 4 == 3)
		{
			cout << ">";
		}
		cout << "  Exit ";

		GoToXY(5, 35);
		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(VK_RIGHT))
		{
			if (choose == 3)
				choose = 0;
			else choose++;
		}
		if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_LEFT))
		{
			if (choose == 0)
				choose = 3;
			else choose--;
		}


		if (GetAsyncKeyState(VK_RETURN))
		{
			switch (choose)
			{
			case 0:
			{
				score = 0;

				Grid tmp;
				grid = tmp;
				InputUserName();

				Save();
				system("cls");
				Play();
				return;
			}
			break;
			case 1:
				if(!Load())
					InputUserName();
				system("cls");
				Play();
				return;
			case 2:
				ScoreBoard();
				break;
			case 3:
				return;	//Thoát chương trình
			}
		}
	}
}

//Hiển thị menu pause
void Game::PauseMenu()
{
	int choose = 0;
	while (true)
	{
		system("cls");
		cout << endl;
		ShowLogo();

		TextColor(14);
		GoToXY(17, 14);
		if (choose % 4 == 0)
		{
			cout << ">";
		}
		cout << "  Restart ";

		GoToXY(17, 16);
		if (choose % 4 == 1)
		{
			cout << ">";
		}
		cout << "  Resume ";

		GoToXY(17, 18);
		if (choose % 4 == 2)
		{
			cout << ">";
		}
		cout << "  Score Board ";

		GoToXY(17, 20);
		if (choose % 4 == 3)
		{
			cout << ">";
		}
		cout << "  Exit ";

		system("pause>nul");
		GoToXY(5, 35);
		
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			Play();
			return;
		}

		if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(VK_RIGHT))
		{
			if (choose == 3)
				choose = 0;
			else choose++;
		}
		if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_LEFT))
		{
			if (choose == 0)
				choose = 3;
			else choose--;
		}
		
		if (GetAsyncKeyState(VK_RETURN))
		if (GetAsyncKeyState(VK_RETURN))
		{
			switch (choose)
			{
			case 0:
			{
				Grid tmp;
				grid = tmp;
				score = 0;
				InputUserName();

				Save();
				system("cls");
				Play();
				return;
			}
			break;
			case 1:
			{
				Play();
				return;
			}
			case 2:
				ScoreBoard();
				break;
			case 3:
				return;	//Thoát chương trình
			}
		}

	}
}

//Hàm chơi game
void Game::Play()
{
	while (!grid.IsOver())
	{
		long _score = 0;
		Show();
		system("pause>nul");

		if (GetAsyncKeyState(VK_UP))
		{	//Nếu các ô chưa được lấp đầy và thực hiện dồn ô được thì mới phát sinh ô mới
			if (grid.SlideUp(_score) && !grid.IsFull() )
			{
				grid.AddNewBlock();
			}
			score += _score;
			isUndid = false;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			Save();
			if (grid.SlideDown(_score) && !grid.IsFull())
				grid.AddNewBlock();
			score += _score;
			isUndid = false;
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			Save();
			if (grid.SlideLeft(_score) && !grid.IsFull())
				grid.AddNewBlock();
			score += _score;
			isUndid = false;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			Save();
			if (grid.SlideRight(_score) && !grid.IsFull())
				grid.AddNewBlock();
			score += _score;
			isUndid = false;
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			system("cls");
			PauseMenu();
			return;
		}
		if (GetAsyncKeyState(VK_BACK))
		{
			Undo();
			isUndid = true;
		}


		SB.AddNewUser(user, score);
		SB.Output();

		if (grid.IsWin() && isShowWin == false)
		{
			Win();
			return;
		}
	}
	
	//Nếu game over thì xoá file log
	std::remove("log.txt");
	GameOver();
	score = 0;
}

//Lưu dữ liệu
void Game::Save()
{

	ofstream f("log.txt");
	if (grid.IsOver())
	{
		Grid tmp;
		tmp.Save(f);
	}
	else grid.Save(f);

	f << user << endl;
	f << score << endl;
	f.close();
}

//Load dữ liệu
bool Game::Load()
{

	ifstream f("log.txt");
	if (f.fail())
	{
		return false;
	}
	grid.Load(score, user, f);

	f.close();
	return true;
	//Load thành công
}

//Chức năng undo 1 lần
void Game::Undo()
{
	ifstream f("log.txt");
	if (f.fail())
	{
		return;
	}
	grid.Load(score, user, f);
	f.close();
}