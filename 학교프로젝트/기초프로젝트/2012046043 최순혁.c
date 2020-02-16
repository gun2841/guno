#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "2012046062 Ã¤µµ¿ø.h"
void gotoxy(int x, int y)
{
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void Picture8()
{
	char b1 = 0xa1;
	char b2 = 0xe1;
	char b3 = 0xe0;
	int i;
	system("cls");
	for(i=1; i<5; i++)
	{
		gotoxy(1+i, 0);
		printf("%c%c", b1,b2);
	}
	gotoxy(1, 2);
	printf("%c%c", b1,b2);
	gotoxy(3, 2);
	printf("%c%c", b1,b3);
	gotoxy(5, 2);
	printf("%c%c", b1,b3);
	gotoxy(7, 2);
	printf("%c%c\n", b1,b2);
	gotoxy(3, 3);
	printf("%c%c", b1,b3);
	gotoxy(5, 3);
	printf("%c%c", b1,b3);
	gotoxy(1, 4);
	printf("%c%c", b1,b2);
	gotoxy(3, 4);
	printf("%c%c", b1,b3);
	gotoxy(5, 4);
	printf("%c%c", b1,b3);
	gotoxy(7, 4);
	printf("%c%c\n", b1,b2);
	gotoxy(1, 5);
	printf("%c%c", b1,b2);
	gotoxy(3, 5);
	printf("%c%c", b1,b2);
	gotoxy(5, 5);
	printf("%c%c", b1,b2);
	gotoxy(7, 5);
	printf("%c%c\n", b1,b2);
}

void Picture6()
{
	char b1 = 0xa1;
	char b2 = 0xe1;
	system("cls");
	gotoxy(1,1);
	printf("%c%c", b1,b2);
	gotoxy(3,1);
	printf("%c%c", b1,b2);
	gotoxy(7,1);
	printf("%c%c", b1,b2);
	gotoxy(9,1);
	printf("%c%c", b1,b2);
	gotoxy(3,2);
	printf("%c%c", b1,b2);
	gotoxy(7,2);
	printf("%c%c", b1,b2);
	gotoxy(3,3);
	printf("%c%c", b1,b2);
	gotoxy(7,3);
	printf("%c%c", b1,b2);
	gotoxy(3,4);
	printf("%c%c", b1,b2);
	gotoxy(7,4);
	printf("%c%c", b1,b2);
	gotoxy(1,5);
	printf("%c%c", b1,b2);
	gotoxy(3,5);
	printf("%c%c", b1,b2);
	gotoxy(7,5);
	printf("%c%c", b1,b2);
	gotoxy(9,5);
	printf("%c%c", b1,b2);
}
