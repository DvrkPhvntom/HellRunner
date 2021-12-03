#include "Const.h"
extern int music;
extern int bar[width][mheight], x, y, thread1;
using namespace std;

const int start = 5, num = 5, fstart = 20;
string points[num] = { "New game", "Continue", "Settings", " About", " Check" };

int Menu()
{
	system("cls");

	// Print main
	gxy(10, fstart + 1);
	printf("!!                              R    R    RUNNER    R         R               !!");
	gxy(10, fstart + 2);
	printf("!!                  !!          R    R    R         R         R               !!                  !!");
	gxy(10, fstart + 3);
	printf("!!             !!   !!          R    R    R         R         R               !!             !!   !!");
	gxy(10, fstart + 4);
	printf("!!   !!        !!   !!          RUNNER    RUNNER    R         R               !!   !!   !!   !!   !!");
	gxy(10, fstart + 5);
	printf("!!   !!   !!   !!   !!          R    R    R         R         R               !!   !!   !!   !!   !!");
	gxy(10, fstart + 6);
	printf("!!   !!   !!   !!   !!          R    R    R         R         R               !!   !!   !!   !!   !!");
	gxy(10, fstart + 7);
	printf("======================          R    R    RUNNER    RUNNER    RUNNER          ======================");


	// Print points
	for (int i = 0; i < num; i++)
	{
		gxy(55, start + i * 3);
		printf("%s", points[i].c_str());
	}


	int ex = -2;
	int cur = 1, x = 50, y = start;
	gxy(x, y);
	printf("--->");
	while (ex == -2)
	{
		// Chose point of menu
		switch (_getch())
		{
		case 27: ex = -1;
			break;
		case 72:
			gxy(x, y);
			printf("    ");
			if (cur != 1)
			{
				cur--;
				y -= 3;
			}
			else
			{
				cur = num;
				y = start + (num - 1) * 3;
			}
			break;
		case 80:
			gxy(x, y);
			printf("    ");
			if (cur != num)
			{
				cur++;
				y += 3;
			}
			else
			{
				cur = 1;
				y = start;
			}
			break;
		case 13: ex = 0;
			break;
		}
		gxy(x, y);
		printf("--->");
	}
	if (ex == 0) { ex = cur; }
	return ex;
}