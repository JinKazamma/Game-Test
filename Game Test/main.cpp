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
	void getposition()
	{
		cout << row<<"\t" << col << endl;
	}
	void moveleft()
	{
		if (col - 1 >= 0 && !(board[row][col - 1]))
		{
			board[row][col - 1] = true;
			board[row][col] = false;
			col--;
		}
		else
		{
			cout << "Ход не возможен" << endl;
		}
	}
	void moveright()
	{
		if (col + 1 <= 7 && !(board[row][col + 1]))
		{
			board[row][col + 1] = true;
			board[row][col] = false;
			col++;
		}
		else
		{
			cout << "Ход не возможен" << endl;
		}
	}
	void moveup()
	{
		if (row - 1 >=0  && !(board[row-1][col]))
		{
			board[row-1][col] = true;
			board[row][col] = false;
			col--;
		}
		else
		{
			cout << "Ход не возможен" << endl;
		}
	}
	void movedown()
	{
		if (row + 1 <= 7 && !(board[row + 1][col]))
		{
			board[row + 1][col] = true;
			board[row][col] = false;
			col++;
		}
		else
		{
			cout << "Ход не возможен" << endl;
		}
	}

};
void SetFigurs(vector<Figure*>fig)
{
	for (int i = 0; i <= 9; i++)
		{
		fig.push_back(new Figure);
		fig[i]->SetColor("white");
		}	
}

int main()
{
	setlocale(LC_ALL, "ru");

	vector <Figure*> fw;
	vector <Figure*> fb;

	SetFigurs(fw);
	fw[4]->getposition();
	return 0;
}