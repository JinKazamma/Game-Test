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
	void setPositionColor(int str, int stl, string color)
	{
		row = str;
		col = stl;
		board[row][col] = true;
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
void SetFigurs(vector<Figure*>&figW, vector<Figure*>& figB)
{
	int countFor4_6Whitefigure = 0;
	int countFor7_9Whitefigure = 0;
	for (int i = 0; i < 9; i++)
	{
		figW.push_back(new Figure);
		if (i < 3)
		{
			figW.back()->setPositionColor(0, i, "white");
		}
		if(i>2 && i<6)
		{
			
			figW.back()->setPositionColor(1, countFor4_6Whitefigure++, "white");
		}
		if(i>5 && i<9)
		{
			figW.back()->setPositionColor(2, countFor7_9Whitefigure++, "white");
		}
	}
	int countFor1_3blackfigure = 5;
	int countFor4_6blackfigure = 5;
	int countFor7_9blackfigure = 5;
	for (int i = 0; i < 9; i++)
	{
		figB.push_back(new Figure);
		if (i < 3)
		{
			figB.back()->setPositionColor(5, countFor1_3blackfigure++, "white");
		}
		if (i > 2 && i < 6)
		{

			figB.back()->setPositionColor(6, countFor4_6blackfigure++, "white");
		}
		if (i > 5 && i < 9)
		{
			figB.back()->setPositionColor(7, countFor4_6blackfigure++, "white");
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	vector <Figure*> fw;
	//vector <Figure*> fb;
	//fw.push_back(new Figure);
	SetFigurs(fw);
	for (int i = 0; i< fw.size() ; i++)
	{
		fw[i]->getposition();
	}
	return 0;
}