
#include "Const.h"
using namespace std;

extern int x = width / 2, y = height / 2, thread1 = 0;
extern int music = 0;
extern int bar[width][mheight] = {};
int main()
{
	// Setup start window settings
	SetWindow(width * 3, height);
	SetColor(2, 32);
	ShowConsoleCursor(false);
	thread mus(Music);
	mus.detach();


	// Start
	StrtScreen();
	int menu = 1;
	while (menu != -1)
	{
		menu = Menu();
		switch (menu)
		{
		case -1:
			break;
		case 1: Gameplay();
			break;
		case 5:
			Check();
			break;
		default: StrtScreen();
		}
	}
	return 0;
}
