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
	
	void moveleft();
	void moveright();
	void moveup();
	void movedown();
};

int main()
{

	Figure f1;

	return 0;
}