#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;


const int ROWS = 8;
const int COLS = 8;

array<array<bool, COLS>, ROWS> board = {};

class Figure 
{
private:
	int row = 0;
	int col = 0;
	string colorOfFigure;
public:
	void setPosition(int str, int stl)
	{
		row = str;
		col = stl;
		board[row][col] = true;
	}
	void SetColor(string color)
	{
		colorOfFigure = color;
	}
	void moveleft()
	{
		if (col - 1 >= 0 && !(board[row][col - 1]))
		{
			board[row][col - 1] = true;
			board[row][col] = false;
			col -= 1;
		}
		else
		{
			cout << "Ход не возможен";
		}
	}
	void moveright();
	void moveup();
	void movedown();
};

int main()
{

	Figure f1;
	f1.setPosition(1, 1);
	return 0;
}