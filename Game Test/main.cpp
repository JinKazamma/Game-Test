#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Doska
{
private:
	int stroka[8] = { 1,2,3,4,5,6,7,8 };
	int stolbec[8] = { 1,2,3,4,5,6,7,8 };
public:
	virtual void moveleft() = 0;
	virtual void moveright() = 0;
	virtual void moveup() = 0;
	virtual void movedown() = 0;
};
class figure
{
private:
	
};