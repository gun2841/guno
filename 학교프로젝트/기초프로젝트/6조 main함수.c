#include "2012046062 채도원.h"
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int num;
	printf("모양을 출력합니다. 원하시는 모양을 입력 하세요\n");
	printf("1 : 숫자2모양 \n2 : 숫자3모양 \n3 : 숫자4모양 \n4 : 숫자5모양 \n5 : 숫자6모양 \n");
	printf("6 : 뚫려있는 탑모양 \n7 : 탑모양 \n8 : 모래시계모양\n9 : T모양 \n");
	
	scanf("%d", &num);
	system("cls");


	switch(num)
	{
	case 1:
		Picture1();
		break;
	case 2:
		Picture2();
		break;
	case 3:
		Picture3();
		break;
	case 4:
		Picture4();
		break;
	case 5:
		Picture5();
		break;
	case 6:
		Picture6();
		break;
	case 7:
		Picture7();
		break;
	case 8:
		Picture8();
		break;
	case 9:
		Picture9();
		break;
	case 10:
		Picture10();
		break;

	
	}
	return 0;
}