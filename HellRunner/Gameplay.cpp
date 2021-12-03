#include "Const.h"

extern int music;
extern int bar[width][mheight], x, y, thread1;
using namespace std;

// Environment
void setEnv(int l, int r, int h, int d)
{
	for (int i = l; i <= r; i++)
	{
		for (int j = h; j <= d; j++)
		{
			bar[i][j] = 1;
		}
	}
}

// Rebuilding
void reb()
{
	system("cls");
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			gxy(1 + i * 3, j);
			if (bar[i][j + y - height / 2] == 1)
			{
				cout << "*";
			}
		}
	}
}


void Gameplay(void)
{

	// Barriers
	int i, j;
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < mheight; j++) { bar[i][j] = 0; }
	}

	// Environment
	setEnv(21, 21, 5, 19);
	setEnv(19, 19, 4, 10);
	setEnv(5, 23, 3, 3);
	setEnv(5, 23, 20, 20);
	setEnv(23, 23, 4, 18);
	setEnv(5, 5, 4, 19);


	// Start
	x = width / 2;
	y = height / 2;
	reb();
	gxy(1 + x * 3, y);
	cout << "&";
	int c;

	// Motion
	while (1)
	{
		c = _getch();
		if (c == 27) { break; }
		gxy(1 + x * 3, height / 2);
		cout << " ";

		// To the Right
		if (c == 77)
		{
			if (x == width - 1)
			{
				if (bar[0][y] == 0) { x = 0; }
			}
			else if (bar[x + 1][y] == 0) { x++; }
		}

		// To the Left
		else if (c == 75)
		{
			if (x == 0)
			{
				if (bar[width - 1][y] == 0) { x = width - 1; }
			}
			else if (bar[x - 1][y] == 0) { x--; }
		}

		// Down
		else if (c == 80)
		{
			if (bar[x][y + 1] == 0)
			{
				y++;
				reb();
			}
		}

		// Up
		else if (c == 72)
		{
			if (y > 0)
			{
				if (bar[x][y - 1] == 0)
				{
					y--;
					reb();
				}
			}
		}

		gxy(1 + x * 3, height / 2);
		cout << "&";
	}
}


// Check map
void Check(void)
{
	gxy(0, 0);
	for (int i = 0; i < mheight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << " " << bar[j][i] << " ";
		}
		cout << "\n";
	}
	gxy(47, mheight + 1);
	printf("Press any key to continue");
	while (_getch() == -1);
}