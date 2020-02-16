#include <iostream>
#include "bus.h"
#include <Windows.h>
using namespace std;
void gotoxy(int x, int y);
int main(){
	BUS A;
	char menu;

	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hC, &csbi);


	do{
		system("cls");

		for (int i = 5; i<17; i++)
		{
			gotoxy(18, i);
			SetConsoleTextAttribute(hC, 11);
			cout << "■";
			gotoxy(64, i);
			cout << "■";
		}
		gotoxy(18, 5);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■";
		gotoxy(18, 17);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■";
		gotoxy(33, 2);

		SetConsoleTextAttribute(hC, 7);
		gotoxy(28, 7);
		cout << "<청주 고속버스 예약 관리>";
		gotoxy(34, 10);
		cout << "1. 운행 안내" << endl;
		gotoxy(34, 11);
		cout << "2. 예약 확인" << endl;
		gotoxy(34, 12);
		cout << "3.  종   료 " << endl;
		gotoxy(34, 13);
		cout << "메뉴 선택 : ";
		cin >> menu;
		cout << endl << endl << endl;
		switch (menu){
		case '1':
			A.schedule();
			break;
		case '2':
			A.print();
			break;
		case '3':
			gotoxy(34, 18);
			exit(1);
			break;
		default :
			gotoxy(30, 14);
			cout << "잘못 입력하셨습니다.";
			gotoxy(25, 15);
			system("pause");
			break;
		}
		cout << endl;
	} while (1);
	
}


