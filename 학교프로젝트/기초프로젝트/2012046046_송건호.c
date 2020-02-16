#include <stdio.h>
#include "2012046062 Ã¤µµ¿ø.h"
#include <windows.h>

void Picture9()
{
	int i;
	char a1=0xa1, a2=0xe1;
	gotoxy(3,1);
	for(i=0;i<6;i+=2)
		printf("%c%c",a1,a2);
	gotoxy(1,2);
	printf("%c%c",a1,a2);
	gotoxy(9,2);
	printf("%c%c",a1,a2);
	gotoxy(1,3);
	printf("%c%c",a1,a2);
	gotoxy(9,3);
	printf("%c%c",a1,a2);
	gotoxy(1,4);
		for(i=0;i<5;i++)
			printf("%c%c",a1,a2);
	gotoxy(1,5);
	printf("%c%c",a1,a2);
	gotoxy(9,5);
	printf("%c%c",a1,a2);
}

void Picture10()
{
	int i;
	char a1=0xa1, a2=0xe1;
	for(i=0;i<10;i+=2)
		printf("%c%c",a1,a2);
	gotoxy(5,2);
	printf("%c%c", a1,a2);
	gotoxy(5,3);
	printf("%c%c", a1,a2);
	gotoxy(5,4);
	printf("%c%c", a1,a2);
	gotoxy(5,5);
	printf("%c%c", a1,a2);
}

void Picture4()
{
	int i;
	char a1=0xa1, a2=0xe1;
	for(i=0;i<10;i+=2)
		printf("%c%c",a1,a2);
	gotoxy(1,2);
	printf("%c%c", a1,a2);
	gotoxy(1,3);
		for(i=0;i<10;i+=2)
		printf("%c%c",a1,a2);
		gotoxy(9,4);
		printf("%c%c", a1,a2);
		gotoxy(1,5);
		for(i=0;i<10;i+=2)
		printf("%c%c", a1,a2);
}