#include <iostream>
#include<stdlib.h>
#include <conio.h>
#include<Windows.h>
#include <vector>
#include <string>
#include <iomanip>
#include <time.h>
#include "bus.h"
#pragma warning (disable:4996)
using namespace std;


void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void BUS::reserve(string str, int time, int run, int charge)
{
	S s;
	s.charge = charge;
	s.str = str;
	s.run = run;
	s.time = time;
	s1.push_back(s);
}
bool BUS::reservemenu(void)
{
	char key;
	do{
		gotoxy(28, 6);
		cout << "���� �Ͻðڽ��ϱ� ? (Y/N)";
		key = getch();
		if (key == 'Y' || key == 'y')
			return 1;
		else if (key == 'n' || key == 'N')
			return 0;
	} while (1);
}
void BUS::schedule(void){
	system("cls");
	char menu;
	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hC, &csbi);

	for (int i = 2; i<16; i++)
	{
		gotoxy(16, i);
		SetConsoleTextAttribute(hC, 11);
		cout << "��";
		gotoxy(60, i);
		cout << "��";
	}
	gotoxy(16, 1);
	cout << "������������������������";
	gotoxy(16, 16);
	cout << "������������������������";
	gotoxy(33, 2);
	SetConsoleTextAttribute(hC, 7);
	cout << "<���� �ȳ�>";
	gotoxy(18, 4);
	cout << "   ��  ��\t �ҿ�  �ð�\t  ��    ��" << endl;
	gotoxy(18, 5);
	cout << "1. ��  ��\t 1�ð� 40��\t   7,700 " << endl;
	gotoxy(18, 6);
	cout << "2. ������\t 1�ð� 40��\t   8,300 " << endl;
	gotoxy(18, 7);
	cout << "3. ��  ��\t 1�ð� 50��\t   8,100 " << endl;
	gotoxy(18, 8);
	cout << "4. ���뱸\t 2�ð� 25��\t   11,300" << endl;
	gotoxy(18, 9);
	cout << "5. ��  ��\t 3�ð� 10��\t   17,400" << endl;
	gotoxy(18, 10);
	cout << "6. ���λ�\t 3�ð� 10��\t   17,000" << endl;
	gotoxy(18, 11);
	cout << "7. ��  ��\t 2�ð� 50��\t   12,900" << endl;
	gotoxy(18, 12);
	cout << "8. ��  ��\t 1�ð�  5��\t   7,300" << endl;
	gotoxy(18, 13);
	cout << "�Է��ϼ��� : ";
	cin >> menu;
	timetable(menu);
}
void BUS::timetable (char menu){
	switch (menu)
	{
	case '1':
		system("cls");
		gangnam();
		break;
	case '2':
		system("cls");
		dongseoul();
		break;
	case '3':
		system("cls");
		sangbong();
		break;
	case '4':
		system("cls");
		dongdaegu();
		break;
	case '5':
		system("cls");
		busan();
		break;
	case '6':
		system("cls");
		southbusan();
		break;
	case '7':
		system("cls");
		gwangju();
		break;
	case '8':
		system("cls");
		sunsan();
		break;
	default:
		gotoxy(18, 14);
		cout << " �߸� �Է��ϼ̽��ϴ�." << endl;
		gotoxy(18, 15);
		system("pause");
		break;
	}

}
void BUS::print(void){
	char a;
	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hC, &csbi);
	system("cls");
	gotoxy(15, 2);
	SetConsoleTextAttribute(hC, 11);
	cout << "��������������������������";

	for (int i = 3; i<s1.size()+13; i++)
	{
		gotoxy(15, i);
		cout << "��";
		gotoxy(63, i);
		cout << "��";
	}
	gotoxy(15, s1.size() + 13);
	cout << "��������������������������";
	SetConsoleTextAttribute(hC, 7);
	gotoxy(19, 4);
	cout << "����\t ������\t ���\t ����ð�\t �ð�" << endl;
	for (unsigned int i = 0; i < BUS::s1.size(); i++){
		gotoxy(19, 5 + i);
		cout << " " << i + 1 << "    " << BUS::s1[i].str << "   ";
		cout << BUS::s1[i].charge << "\t  ";
		cout << (BUS::s1[i].run) / 60 << "��" << setw(2) << setfill('0') << (BUS::s1[i].run) % 60 << "��" << "       ";
		cout << (BUS::s1[i].time) / 60 << " : " << setw(2) << setfill('0') << (BUS::s1[i].time) % 60 << endl;
	}
	gotoxy(19, 6 + BUS::s1.size());
	cout << "1. ���� ȭ��";
	gotoxy(19, 7 + BUS::s1.size());
	cout << "2. ���� ���";
	gotoxy(19, 8 + BUS::s1.size());
	cout << "�޴� ���� : ";
	cin >> a;
	int i = 0;
	switch (a){
	case '1':
		break;
	case '2':
		gotoxy(19, 9 + BUS::s1.size());
		cout << "��� �� ����� �����ϼ��� : ";
		cin >> i;
		if (i <= BUS::s1.size() && i > 0){
			s1.erase(s1.begin() + i - 1);
			gotoxy(19, 11 + BUS::s1.size());
			cout << "���� ��� �Ǿ����ϴ�.";
			gotoxy(19, 12 + BUS::s1.size());
			system("pause");
		}
		else{
			gotoxy(19, 10 + BUS::s1.size());
			cout << "���� ����Դϴ�.";
			gotoxy(19, 11 + BUS::s1.size());
			system("pause");
		}
		break;
	default:
		gotoxy(19, 9 + BUS::s1.size());
		cout << "�߸��Է��ϼ̽��ϴ�.";
		system("pause");
		break;
	}
}
//�ð�ǥ
void BUS::gangnam()
{
	time_t curr;
	struct tm *d;
	curr = time(NULL);
	d = localtime(&curr);
	gotoxy(60, 1);
	cout << d->tm_year + 1900 << "�� " << d->tm_mon + 1 << "�� " << d->tm_mday << "��" << endl;
	
	
	int i = 3;
	gotoxy(3, 2);
	cout << " û�� -> ����" << endl;
	cout << " 1    ù��  5 : 40" << endl;
	cout << " 2    ���� 23 : 30" << endl;
	for (int n = 6; n < 24; n++){
		cout.width(2);
		cout << i++;
		cout << "      " << n << " : 00" << endl;
	}
	cout << endl;
	if (reservemenu() == 1){
		gotoxy(28, 7);
		cout << "���� ��ȣ�� �����ϼ���. : ";
		cin >> i;
		if (i == 1)
			reserve("����", 340, 100, 7700);
		else if (i == 2)
			reserve("����", 1410, 100, 7700);
		else if (i < 21)
			reserve("����", (i + 3) * 60, 100, 7700);
		else{
			gotoxy(28, 8);
			cout << "�߸� �Է��ϼ̽��ϴ�.";
			gotoxy(28, 9);
			system("pause");
			return;
		}
		gotoxy(28, 8);
		cout << "���� �Ǿ����ϴ�" << endl;
			gotoxy(28, 9);
		system("pause");


	}
	
}
void BUS::dongseoul()
{
	time_t curr;
	struct tm *d;
	curr = time(NULL);
	d = localtime(&curr);
	gotoxy(60, 1);
	cout << d->tm_year + 1900 << "�� " << d->tm_mon + 1 << "�� " << d->tm_mday << "��" << endl;

	int i = 1;
	gotoxy(3, 2);
	cout << "û�� -> ������" << endl;
	for (int n = 06; n < 22; n++){
		cout << i++ << "    " << n << " : 00" << endl;
		cout << i++ << "    " << n << " : 30" << endl;
	}
	cout << "33    21 : 55" << endl;
	if (reservemenu() == 1){
		gotoxy(28, 7);
		cout << "���� ��ȣ�� �����ϼ���. : ";
		cin >> i;
		if (i > 0 && i <33)
			reserve("������", 360 + (i - 1) * 30, 100, 8300);
		else if (i == 33)
			reserve("������", 1315, 100, 8300);
		else{
			gotoxy(28, 8);
			cout << "�߸� �Է��ϼ̽��ϴ�.";
			gotoxy(28, 9);
			system("pause");
			return;
		}
		gotoxy(28, 8);
		cout << "���� �Ǿ����ϴ�" << endl;
		gotoxy(28, 9);
		system("pause");
	}
}
void BUS::sangbong()
{
	time_t curr;
	struct tm *d;
	curr = time(NULL);
	d = localtime(&curr);
	gotoxy(60, 1);
	cout << d->tm_year + 1900 << "�� " << d->tm_mon + 1 << "�� " << d->tm_mday << "��" << endl;

	cout << "û�� -> ���" << endl
		<< "1     6 : 25" << endl
		<< "2     9 : 10" << endl
		<< "3    12 : 10" << endl
		<< "4    15 : 10" << endl
		<< "5    19 : 10" << endl;
	if (reservemenu() == 1){
		gotoxy(28, 7);
		cout << "���� ��ȣ�� �����ϼ���. : ";
		int i;
		cin >> i;
		if (i == 1)
			reserve("��  ��", 385, 110, 8100);
		else if (i>1 && i<6)
			reserve("��  ��", 190 + 180 * i, 110, 8100);
		else{
			gotoxy(28, 8);
			cout << "�߸� �Է��ϼ̽��ϴ�.";
			gotoxy(28, 9);
			system("pause");
			return;
		}
		gotoxy(28, 8);
		cout << "���� �Ǿ����ϴ�" << endl;
		gotoxy(28, 9);
		system("pause");
	}
}
void BUS::dongdaegu()
{
	time_t curr;
	struct tm *d;
	curr = time(NULL);
	d = localtime(&curr);
	gotoxy(60, 1);
	cout << d->tm_year + 1900 << "�� " << d->tm_mon + 1 << "�� " << d->tm_mday << "��" << endl;

	int i = 1;
	cout << "û�� -> ���뱸" << endl;
	for (int n = 6; n < 20; n++)
		cout << i++ << "    " << n << " : 00" << endl;

	if (reservemenu() == 1){
		gotoxy(28, 7);
		cout << "���� ��ȣ�� �����ϼ���. : ";
		cin >> i;
		if (i >0 && i<15)
			reserve("���뱸", 300 + 60 * i, 145, 11300);
		else{
			gotoxy(28, 8);
			cout << "�߸� �Է��ϼ̽��ϴ�.";
			gotoxy(28, 9);
			system("pause");
			return;
		}
		gotoxy(28, 8);
		cout << "���� �Ǿ����ϴ�" << endl;
		gotoxy(28, 9);
		system("pause");
	}
}
void BUS::busan()
{
	time_t curr;
	struct tm *d;
	curr = time(NULL);
	d = localtime(&curr);
	gotoxy(60, 1);
	cout << d->tm_year + 1900 << "�� " << d->tm_mon + 1 << "�� " << d->tm_mday << "��" << endl;

	int charge = 17400;
	int run = 190;
	int i = 1;
	cout << "û�� -> �λ�" << endl;
	for (int n = 6; n < 20; n++){
		cout << i++ << "    " << n++ << " : 00" << endl;
		cout << i++ << "    " << n++ << " : 30" << endl;
	}
	if (reservemenu() == 1){
		gotoxy(28, 7);
		cout << "���� ��ȣ�� �����ϼ���. : ";
		cin >> i;
		if (i >0 && i<11)
			reserve("��  ��", 270 + 90 * i, 190, 17400);
		else{
			gotoxy(28, 8);
			cout << "�߸� �Է��ϼ̽��ϴ�.";
			gotoxy(28, 9);
			system("pause");
			return;
		}
		gotoxy(28, 8);
		cout << "���� �Ǿ����ϴ�" << endl;
		gotoxy(28, 9);
		system("pause");
	}
}
void BUS::southbusan()
{
	time_t curr;
	struct tm *d;
	curr = time(NULL);
	d = localtime(&curr);
	gotoxy(60, 1);
	cout << d->tm_year + 1900 << "�� " << d->tm_mon + 1 << "�� " << d->tm_mday << "��" << endl;

	int i;
	cout << "û�� -> ���λ�" << endl;
	cout << "1     9 : 00" << endl;
	cout << "2    15 : 00" << endl;
	if (reservemenu() == 1){
		gotoxy(28, 7);
		cout << "���� ��ȣ�� �����ϼ���. : ";
		cin >> i;
		if (i == 1)
			reserve("���λ�", 540, 190, 17000);
		else if (i == 2)
			reserve("���λ�", 900, 190, 17000);
		else{
			gotoxy(28, 8);
			cout << "�߸� �Է��ϼ̽��ϴ�.";
			gotoxy(28, 9);
			system("pause");
			return;
		}
		gotoxy(28, 8);
		cout << "���� �Ǿ����ϴ�" << endl;
		gotoxy(28, 9);
		system("pause");
	}
}
void BUS::gwangju()
{
	time_t curr;
	struct tm *d;
	curr = time(NULL);
	d = localtime(&curr);
	gotoxy(60, 1);
	cout << d->tm_year + 1900 << "�� " << d->tm_mon + 1 << "�� " << d->tm_mday << "��" << endl;

	int charge = 12900;
	int run = 170;
	int i = 1;
	cout << "����(�� ~ ��)" << endl << "û�� -> ����" << endl;
	for (int n = 6; n < 22; n = n + 4){
		cout << i++ << "    " << n << " : 00" << endl;
		cout << i++ << "    " << n + 1 << " : 20" << endl;
		cout << i++ << "    " << n + 2 << " : 40" << endl;
	}
	cout << "13    22 : 10" << endl;
	if (reservemenu() == 1){
		gotoxy(28, 7);
		cout << "���� ��ȣ�� �����ϼ���. : ";
		cin >> i;
		if (i >0 && i<13)
			reserve("��  ��", 280 + 80 * i, 170, 12900);
		else if (i == 13)
			reserve("��  ��", 1330, 170, 12900);
		else{
			gotoxy(28, 8);
			cout << "�߸� �Է��ϼ̽��ϴ�.";
			gotoxy(28, 9);
			system("pause");
			return;
		}
		gotoxy(28, 8);
		cout << "���� �Ǿ����ϴ�" << endl;
		gotoxy(28, 9);
		system("pause");
	}
}
void BUS::sunsan()
{
	time_t curr;
	struct tm *d;
	curr = time(NULL);
	d = localtime(&curr);
	gotoxy(60, 1);
	cout << d->tm_year + 1900 << "�� " << d->tm_mon + 1 << "�� " << d->tm_mday << "��" << endl;

	int charge = 7300;
	int run = 65;
	int i = 1;
	cout << "û�� -> ����" << endl;
	for (int n = 6; n < 20; n){
		cout << i++ << "    " << n << " : 00" << endl;
		cout << i++ << "    " << n++ << " : 30" << endl;
	}
	if (reservemenu() == 1){
		gotoxy(28, 7);
		cout << "���� ��ȣ�� �����ϼ���. : ";
		cin >> i;
		if (i >1 && i<29)
			reserve("��  ��", 330 + 30 * i, 65, 7300);
		else{
			gotoxy(28, 8);
			cout << "�߸� �Է��ϼ̽��ϴ�.";
			gotoxy(28, 9);
			system("pause");
			return;
		}
		gotoxy(28, 8);
		cout << "���� �Ǿ����ϴ�" << endl;
		gotoxy(28, 9);
		system("pause");
	}
}
// �ð�ǥ
BUS::BUS()
{
}
BUS::BUS(S* s1)
{

}
BUS::BUS(const BUS& bus)
{

}
BUS::~BUS()
{

}