#include "2012046062 ä����.h"
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int num;
	printf("����� ����մϴ�. ���Ͻô� ����� �Է� �ϼ���\n");
	printf("1 : ����2��� \n2 : ����3��� \n3 : ����4��� \n4 : ����5��� \n5 : ����6��� \n");
	printf("6 : �շ��ִ� ž��� \n7 : ž��� \n8 : �𷡽ð���\n9 : T��� \n");
	
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