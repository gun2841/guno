#include "2012046062 Ã¤µµ¿ø.h"
#include <stdio.h>
#include <Windows.h>
void gotoxy(int x,int y);
void Picture5()
{
	char b1=0xa1;
	char b2=0xe1;
	int i;
	for(i=0;i<10;i+=2)
	{
		printf("%c%c",b1,b2);
	}
	for(i=0;i<6;i++)
	{
		gotoxy(1, i);
		printf("%c%c", b1,b2);
	}
	for(i=0;i<10;i+=2)
	{
		gotoxy(3+i, 3);
		printf("%c%c", b1,b2);
	}
		gotoxy(11,5);
		printf("%c%c", b1, b2);
		gotoxy(11,4);
		printf("%c%c", b1, b2);

		for(i=0;i<10;i+=2)
		{
		gotoxy(3+i, 5);
		printf("%c%c", b1, b2);
		}
}
void Picture7()
{
	char b1=0xa1;
	char b2=0xe1;
	int i;
	
	for(i=0;i<10;i+=2)
	{
		printf("%c%c",b1,b2);
	}
	gotoxy(3,2);
	printf("%c%c", b1, b2);
	gotoxy(5,2);
	printf("%c%c", b1, b2);
	gotoxy(7,2);
	printf("%c%c", b1, b2);
	gotoxy(3,3);
	printf("%c%c", b1, b2);
	gotoxy(7,3);
	printf("%c%c", b1, b2);
	gotoxy(3,4);
	printf("%c%c", b1, b2);
	gotoxy(5,4);
	printf("%c%c", b1, b2);
	gotoxy(7,4);
	printf("%c%c", b1, b2);

		for(i=0;i<10;i+=2)
	{
		gotoxy(1+i,5);
		printf("%c%c",b1,b2);
	}
}
