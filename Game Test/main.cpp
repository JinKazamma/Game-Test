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
	pair<int, int> GetPosition() const
	{
		return make_pair(row, col);
	}
	void SHOWtposition()
	{
		cout << row<<"\t" << col <<"\t"<< colorOfFigure << endl;
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
void SetFigurs(vector<Figure*>&figW, vector<Figure*>&figB)
{
	int countFor4_6Whitefigure = 0;
	int countFor7_9Whitefigure = 0;
	int countFor1_3blackfigure = 5;
	int countFor4_6blackfigure = 5;
	int countFor7_9blackfigure = 5;
	for (int i = 0; i < 9; i++)
	{
		figW.push_back(new Figure);
		figB.push_back(new Figure);
		if (i < 3)
		{
			figW.back()->setPositionColor(0, i, "white");
			figB.back()->setPositionColor(5, countFor1_3blackfigure++, "Black");
		}
		if(i>2 && i<6)
		{
			
			figW.back()->setPositionColor(1, countFor4_6Whitefigure++, "white");
			figB.back()->setPositionColor(6, countFor4_6blackfigure++, "Black");
		}
		if(i>5 && i<9)
		{
			figW.back()->setPositionColor(2, countFor7_9Whitefigure++, "white");
			figB.back()->setPositionColor(7, countFor7_9blackfigure++, "Black");
		}
	}
	
}
void MoveAi(vector <Figure*> BlackFigure)
{
	int index = rand() % BlackFigure.size();
	auto fig = BlackFigure[index];
	auto [row, col] = fig->GetPosition();
	// Случайное направление для хода
	bool down = rand() % 2;
	bool right = !down;
	if (down)
	{
		// Ход вниз
		if (row + 1 <= 7 && !(board[row + 1][col]))
		{
			board[row + 1][col] = true;
			board[row][col] = false;
			fig->movedown();
		}
	}
	else
	{
		// Ход вправо
		if (col + 1 <= 7 && !(board[row][col + 1]))
		{
			board[row][col + 1] = true;
			board[row][col] = false;
			fig->moveright();
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int choiseFigure;
	string choiseSide;
	vector <Figure*> WhiteFigure;
	vector <Figure*> BlackFigure;
	SetFigurs(BlackFigure, WhiteFigure);
	bool gameover = false;
	while (!gameover)
	{ 
		int Counter;
		cout << "выберите белую фигуру"; cin >> choiseFigure;
		cout << "выберите направление "; cin >> choiseSide;
		if (choiseSide == "left")
			WhiteFigure[choiseFigure]->moveleft();
		if (choiseSide == "right")
			WhiteFigure[choiseFigure]->moveright();
		if (choiseSide == "up")
			WhiteFigure[choiseFigure]->moveup();
		if (choiseSide == "down")
			WhiteFigure[choiseFigure]->movedown();
		for (int i = 0; i < WhiteFigure.size(); i++)
		{
			/*pair<int,int>currentP1 = WhiteFigure[i]->GetPosition();
			if()*/
			
			auto [row, col] = WhiteFigure[i]->GetPosition();
			if (board[row][col])
			Counter++;

		if(Counter == WhiteFigure.size());
		{cout << "Black figures are on white positions. You won!" << endl;
		gameover = true;
		break;
		}
	}
		
		MoveAi(BlackFigure)
	
	return 0;
}