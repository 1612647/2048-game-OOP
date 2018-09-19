#include "Block.h"

Block::Block()
{
	x = y = 1;
	value = 0;
}
Block::Block(int _x, int _y)
{
	x = _x;
	y = _y;
	value = 0;
}
Block::Block(int _x, int _y, long _value)
{
	x = _x;
	y = _y;
	value = _value;
}
bool Block::operator==(Block b)
{
	return value == b.GetValue();

}
int Block::GetX()
{
	return x;
}
int Block::GetY()
{
	return y;
}
long Block::GetValue()
{
	return value;
}
void Block::SetValue(long _value)
{
	value = _value;
}

bool Block::IsEmpty()
{
	return (value == 0);
}

//Hiện thị khối vuông
void Block::Show()
{
	switch (value)
	{
	case 0:
		TextColor(176);
		break;
	case 2:
		TextColor(240);
		break;
	case 4:
		TextColor(124);
		break;
	case 8:
		TextColor(137);
		break;
	case 16:
		TextColor(59);
		break;
	case 32:
		TextColor(110);
		break;
	case 64:
		TextColor(42);
		break;
	case 128:
		TextColor(169);
		break;
	case 256:
		TextColor(228);
		break;
	case 512:
		TextColor(222);
		break;
	case 1024:
		TextColor(203);
		break;
	case 2048:
		TextColor(14);
		break;
	case 4096:
		TextColor(27);
		break;
	case 8192:
		TextColor(159);
		break;
	default:
		TextColor(241);
	}

	GoToXY(x, y - 1);
	cout << setw(block_width) << " ";

	GoToXY(x, y);
	if (value > 0)
	{
		int width = to_string(value).length();
		cout << setw((block_width - width) / 2 + width) << value;
		for (int i = 0; i < block_width - (block_width - width) / 2 - width; i++)
			cout << " ";
	}
	else cout << setw(block_width) << " " << endl;

	GoToXY(x, y + 1);
	cout << setw(block_width) << " " << endl;

	TextColor(7);	//về màu mặc định
}

//Set ô trống
void Block::SetEmpty()
{
	value = 0;
}
//Di chuyển đến ô dest
void Block::Move(Block &dest)
{
	dest.value = value;
	SetEmpty();
}
//Gộp ô join
void Block::Merge(Block &join)
{
	value += join.value;
	join.SetEmpty();
}

