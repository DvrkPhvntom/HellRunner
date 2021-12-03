#include "Const.h"

const int start = 12, tstep = 72, achtung = 24;
extern int music;
extern int x, y, thread1;
void fire()
{

	for (int i = start; i < start + 6; i++)
	{
		gxy(10, i);
		printf("                      ");
	}
	for (int i = start; i < start + 6; i++)
	{
		gxy(88, i);
		printf("                      ");
	}

	if (thread1 != 1) { return; }

	Sleep(tstep);
	gxy(10, start + 5);
	printf("!!   !!   !!   !!   !!");
	gxy(88, start + 5);
	printf("!!   !!   !!   !!   !!");

	if (thread1 != 1) { return; }

	Sleep(tstep);
	gxy(10, start + 4);
	printf("!!   !!   !!   !!   !!");
	gxy(88, start + 4);
	printf("!!   !!   !!   !!   !!");

	if (thread1 != 1) { return; }

	Sleep(tstep);
	gxy(10, start + 3);
	printf("!!   !!        !!   !!");
	gxy(88, start + 3);
	printf("!!   !!        !!   !!");

	if (thread1 != 1) { return; }

	Sleep(tstep);
	gxy(10, start + 2);
	printf("!!             !!   !!");
	gxy(88, start + 2);
	printf("!!             !!   !!");

	if (thread1 != 1) { return; }

	Sleep(tstep);
	gxy(10, start + 1);
	printf("!!                  !!");
	gxy(88, start + 1);
	printf("!!                  !!");

	if (thread1 != 1) { return; }

	Sleep(tstep);
	gxy(10, start);
	printf("!!                    ");
	gxy(88, start);
	printf("!!                    ");

	if (thread1 != 1) { return; }

	Sleep(tstep);
}

HANDLE h;

void StrtScreen1()
{

	music = 1;
	thread1 = 1;

	Sleep(500);
	if (thread1 != 1) { return; }

	system("cls");
	for (int i = 0; i < 22; i++)
	{
		gxy(10 + i, start + 6);
		printf("=");
		gxy(88 + i, start + 6);
		printf("=");
		Sleep(30);

		if (thread1 != 1) { return; }
	}

	Sleep(120);
	
	int i = 0;
	while (i != 4 and thread1 == 1)
	{
		fire();
		i++;
	}

	if (thread1 != 1) { return; }

	Sleep(360);
	gxy(42, start + 6);
	printf("          RUNNER              RUNNER");
	gxy(42, start);
	printf("R    R              R");
	fire();

	if (thread1 != 1) { return; }

	gxy(42, start + 5);
	printf("          R                   R");
	gxy(42, start + 1);
	printf("R    R              R");
	fire();

	if (thread1 != 1) { return; }

	gxy(42, start + 4);
	printf("          R                   R");
	gxy(42, start + 2);
	printf("R    R              R");
	fire();

	if (thread1 != 1) { return; }

	gxy(42, start + 3);
	printf("RUNNER");
	gxy(62, start + 3);
	printf("R");
	fire();

	if (thread1 != 1) { return; }

	Sleep(360);

	if (thread1 != 1) { return; }

	gxy(52, start + 3);
	printf("RUNNER");
	gxy(72, start + 3);
	printf("R");
	fire();

	if (thread1 != 1) { return; }

	gxy(72, start + 2);
	printf("R");
	gxy(52, start + 2);
	printf("R");
	gxy(42, start + 4);
	printf("R    R");
	gxy(62, start + 4);
	printf("R");
	fire();

	if (thread1 != 1) { return; }

	gxy(72, start + 1);
	printf("R");
	gxy(52, start + 1);
	printf("R");
	gxy(42, start + 5);
	printf("R    R");
	gxy(62, start + 5);
	printf("R");
	fire();

	if (thread1 != 1) { return; }

	gxy(52, start);
	printf("RUNNER");
	gxy(72, start);
	printf("R");
	gxy(42, start + 6);
	printf("R    R");
	gxy(62, start + 6);
	printf("RUNNER");
	fire();

	if (thread1 != 1) { return; }

	Sleep(360);
	i = 0;
	while (i != 4 and thread1 == 1)
	{
		fire();
		i++;
	}

	if (thread1 != 1) { return; }

	gxy(47, achtung);
	printf("Press any key to continue");
	while (_getch() == -1);
}

void StrtScreen()
{
	music = 0;
	thread thr(StrtScreen1);
	if (_getch() != -1) { thread1 = 0; }
	thr.join();
}

