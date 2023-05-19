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
public:
	void setPositionColor(int str, int stl)
	{
		row = str;
		col = stl;
		board[row][col] = true;
	}
	pair<int, int> GetPosition() const
	{
		return make_pair(row, col);
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
			row--;
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
			row++;
		}
		else
		{
			cout << "Ход не возможен" << endl;
		}
	}

};
void SetFigurs(vector<Figure*>& figB, vector<Figure*>& figW )
{
	int countFor4_6Whitefigure = 0;
	int countFor7_9Whitefigure = 0;
	int countFor1_3blackfigure = 5;
	int countFor4_6blackfigure = 5;
	int countFor7_9blackfigure = 5;
	for (int i = 0; i < 9; i++)
	{
		figB.push_back(new Figure);
		figW.push_back(new Figure);
		if (i < 3)
		{
			figB.back()->setPositionColor(0, i);
			figW.back()->setPositionColor(5, countFor1_3blackfigure++);
		}
		if(i>2 && i<6)
		{
			
			figB.back()->setPositionColor(1, countFor4_6Whitefigure++);
			figW.back()->setPositionColor(6, countFor4_6blackfigure++);
		}
		if(i>5 && i<9)
		{
			figB.back()->setPositionColor(2, countFor7_9Whitefigure++);
			figW.back()->setPositionColor(7, countFor7_9blackfigure++);
		}
	}
	
}
void MoveAi(vector <Figure*> BlackFigure)
{
	bool step = false;
	//рандомный выбор фигуры
	while (!step) 
	{
		int index = rand() % BlackFigure.size();
		auto [row, col] = BlackFigure[index]->GetPosition();
		//Движ вниз
		if (row + 1 <= 7 && !(board[row + 1][col]))
		{
			BlackFigure[index]->movedown();
			step = true;
		}
		//Движе вправо
		if (col + 1 <= 7 && !(board[row][col + 1])&&(!step))
		{
			BlackFigure[index]->moveright();
			step = true;
		}
	}
}
void Showboard(vector<Figure*>&WhiteFigure)
{
	int countB = 0;
	int countW = 0;
		for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			if (board[r][c])
			{
				bool white = false;
				for (int j = 0; j < WhiteFigure.size(); j++)
				{
					auto [row, col] = WhiteFigure[j]->GetPosition();
					if (row == r && col == c)
					{
						white = true;
						cout << "W"<< countW<<" ";
						countW++;
						break;
					}
				}
				if (!white)
				{
					cout << "B" << countB << " ";;
					countB++;
				}
			}
			else
			{
				cout << " O ";
			}
		}
		cout << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	int choiseFigure;
	string choiseSide;
	vector <Figure*> BlackFigure;
	vector <Figure*> WhiteFigure;
	SetFigurs(BlackFigure, WhiteFigure);
	bool gameover = false;
	while (!gameover)
	{
		int Counter=0;
		Showboard(WhiteFigure);
		cout << "выберите цифру белой фигуры  "; cin >> choiseFigure;
		cout << "выберите направление: l/r/u/d "; cin >> choiseSide;
		if (choiseSide == "l")
			WhiteFigure[choiseFigure]->moveleft();
		if (choiseSide == "r")
			WhiteFigure[choiseFigure]->moveright();
		if (choiseSide == "u")
			WhiteFigure[choiseFigure]->moveup();
		if (choiseSide == "d")
			WhiteFigure[choiseFigure]->movedown();
		for (int i = 0; i < WhiteFigure.size(); i++)
		{
			auto [row, col] = WhiteFigure[i]->GetPosition();
			if (row == 0 && col == 0 || row == 0 && col == 1 || row == 0 && col == 2 ||
				row == 1 && col == 0 || row == 1 && col == 1 || row == 1 && col == 2 ||
				row == 2 && col == 0 || row == 2 && col == 1 || row == 2 && col == 2)
				Counter++;

			if (Counter == WhiteFigure.size())
			{
			cout << "Black figures are on white positions. You won!" << endl;
			gameover = true;
			break;
			}
		}
		Showboard(WhiteFigure);
		cout << "========ХОД ИИ=========" << endl;
		MoveAi(BlackFigure);
		
	}
	return 0;
}