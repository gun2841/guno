#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
//�Լ����������������������Ѥ�
void display_rule(void);
void sample_Dowon_map(void);
//�⺻ 10x10
void basic_map();
void display_basic_map(int matrix[][10], int tx[], int ty[]);
void make_treasure(int tx[], int ty[]);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void basic_control(int tx[], int ty[]);
//�⺻ 15x15
void display_basic_map2(int matrix[][15], int tx[], int ty[]);
void make_treasure2(int tx[], int ty[]);
void move_arrow_key2(char key, int *x1, int *y1, int x_b, int y_b);
void basic_control2(int tx[], int ty[]);
//�⺻ 2020
void display_basic_map3(int matrix[][20], int tx[], int ty[]);
void make_treasure3(int tx[], int ty[]);
void move_arrow_key3(char key, int *x1, int *y1, int x_b, int y_b);
void basic_control3(int tx[], int ty[]);

//�۰�ȣ 10x10
void hard_map();
void hard_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void display_hard_map(int matrix[][10], int tx[], int ty[]);
void hard_treasure(int tx[], int ty[]);
void hard_control(int tx[], int ty[]);
void gotoxy(int x, int y);
//���� 1010
void Dowon_map(void);
void Dowon_MakeTreasure(int tx[], int ty[]);
void Dowon_display_map(int matrix[][11], int tx[], int ty[]); // ���� ��������
void Dowon_arrow_key(char key, int* x1,int *y1, int x_b, int y_b);
void Dowon_game(int tx[], int ty[]); 
//1515
void Dowon_map2(void);
void Dowon_MakeTreasure2(int tx[], int ty[]);
void Dowon_display_map2(int matrix[][11], int tx[], int ty[]); // ���� ��������
void Dowon_arrow_key2(char key, int* x1,int *y1, int x_b, int y_b);
void Dowon_game2(int tx[], int ty[]); 
//2020
void Dowon_map3(void);
void Dowon_MakeTreasure3(int tx[], int ty[]);
void Dowon_display_map3(int matrix[][11], int tx[], int ty[]); // ���� ��������
void Dowon_arrow_key3(char key, int* x1,int *y1, int x_b, int y_b);
void Dowon_game3(int tx[], int ty[]); 
//�������̤����̤��������̤�����
//�١١١١١١١١١١١١١١١١١١١١�
void main(void) //�������̤��̤Ӥ�
{
	int menu,level;
	int tx[7], ty[7]; // ������ ��ǥ
	char key;
	clock_t start, end;// ���۽ð��� ���ð��� �����ϴ� ����
	double pst;
	srand(time(NULL)); // �ð� �ʱ�ȭ
	
	do{
	display_rule(); // ��Ģ ���
	printf("1�� = �⺻�� ");
	printf("2�� = ��ȣ��");
	printf("3�� = ������");
	printf("\n�����ϼ��� : ");
	scanf("%d", &menu);
	switch(menu)
	{
	case 1:
		basic_map();
		break;
	case 2:
		hard_map();
		break;
	case 3:
		sample_Dowon_map();
		break;
	default:
		printf("�߸������̽��ϴ�.");
		break;
	}
		printf("\n�� �Ͻðڽ��ϱ� ?\n");
		printf("y�� �����ø� ����մϴ�. �ƴҰ�� �ٸ� ���� �����ϼ���\n");
		key = getch();
		if(key == 'y' || key == 'Y')
			break;
		system("cls");
	}while(1);

	do{
		printf("���̵��� �����ϼ���  \n");
		printf("1��. 10X10\n");
		printf("2��. 15X15\n");
		printf("3��. 20X20\n");
		scanf("%d", &level);
		if(level == 1 || level == 2 || level == 3)
			break;
	}while(1);

	start = clock(); // ���۽ð�
	 

	switch(menu) // ������ �ش��ϴ� ���� ����
	{
	case 1: //1�����ý� �⺻ ��
		switch(level)
		{
		case 1:
		make_treasure(tx,ty);
		break;
		case 2:
		make_treasure2(tx,ty);
		break;
		case 3:
		make_treasure3(tx,ty);
		break;
		}
		break;
	case 2: // 2�����ý� �ٸ� ��
		hard_treasure(tx,ty);
		break;
	case 3:
		switch(level)
		{
		case 1:
			Dowon_MakeTreasure(tx,ty);
			break;
		case 2:
			Dowon_MakeTreasure2(tx,ty);
			break;
		case 3:
			Dowon_MakeTreasure3(tx, ty);
			break;
		}
	}

	system("cls"); 
	switch(menu)
	{
	case 1:
		switch(level)
		{
		case 1:
		basic_control(tx,ty);
		break;
		case 2:
		basic_control2(tx,ty);
		break;
		case 3:
		basic_control3(tx,ty);
		break;
		}
		break;
	case 2:
		hard_control(tx,ty);
		break;
	case 3:
		switch(level)
		{
		case 1:
			Dowon_game(tx,ty);
			break;
		case 2:
			Dowon_game2(tx,ty);
			break;
		case 3:
			Dowon_game3(tx, ty);
			break;
		}
		break;
	}

	end = clock(); // ������ �ð�
	pst = (double)(end - start) / CLK_TCK;
	gotoxy(1, 13);
	printf("��� �ð� : %.1f ��", pst);
	gotoxy(1, 14);
	printf("��� ã�ҽ��ϴ�. ������ �����մϴ�. \n");
	getch();
	return ;
}
//�١١١١١١١١١١١١١١١١١١١١�
//�⺻ ���
void display_rule(void)
{
	gotoxy(1, 1);
	printf("���� ã��");
	gotoxy(1, 3);
	printf("�Ʒ��� �ٵ��� ����� ���ڿ��� ������\n");
	gotoxy(1, 4);
	printf("������ �ֽ��ϴ�.\n");
	gotoxy(1, 5);
	printf("ȭ��ǥ(�����)Ű�� �������� ã���ϴ�.\n");
	gotoxy(1, 7);
	printf("������ �����ϼ���.\n");
	printf("�����Ͻø� �ش��ϴ� ������ ���ɴϴ�.\n");
}
void gotoxy(int x, int y)
{
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
//�⺻ ��
void basic_map()
{
		int i, j;
			for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 10; j++)
				printf("��");
			printf("\n");
		}
		
}
void basic_control(int tx[], int ty[])
{
	char key;
	int i, j, count = 0;
	int x = 1, y = 1;
	int matrix[11][11] = {0};
	do
	{
		gotoxy(x, y);
		matrix[(x + 1) / 2][y] = 1;
		for(i = 0; i < 2; i++)
			if((x + 1) / 2 == tx[i] && (y == ty[i]))
				matrix[(x + 1) / 2][y] = 2;

		gotoxy(1, 1);
		display_basic_map(matrix,tx,ty);
		gotoxy(x, y);

		if(matrix[(x+1)/2][y]==2)
			printf("��");
		else 
			printf("��");
		count = 0;
		for(i = 1; i <= 10; i++)
			for(j = 1; j <= 10; j++)
				if(matrix[i][j] == 2)
					count += 1;
		gotoxy(1, 12);
		printf("ã�� ����(��)�� ���� : %d", count);
		key = getch();
		move_arrow_key(key, &x, &y, 19,10);
		}while(count < 2);
}
void make_treasure(int tx[], int ty[])
{
	int i;
		for(i = 0; i < 2; i ++)
		{
			do{
				tx[i] = rand()%11;
				ty[i] = rand()%11;
			}while((tx[i] < 1) || (ty[i] < 1));
		}
}
void display_basic_map(int matrix[][11], int tx[], int ty[])
{
	int i, j;
	basic_map();
	for(i = 1; i <= 10; i++)
		for(j = 1; j <= 10; j++)
			if(matrix[i][j] == 1)
			{
				gotoxy(2 * i - 1, j);
				printf("��");
			}
			else if(matrix[i][j] == 2)
			{
				gotoxy(2 * i - 1, j);
				printf("��");
			}
}
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
	case 72:
		*y1 = *y1 - 1;
		if(*y1 < 1) *y1 = 1;
		break;
	case 75:
		*x1 = *x1 - 2;
		if(*x1 < 1) *x1 = 1;
		break;
	case 77:
		*x1 = *x1 + 2;
		if(*x1 > x_b) *x1 = x_b;
		break;
	case 80:
		*y1 = *y1 + 1;
		if(*y1 > y_b) *y1 = y_b;
		break;
	default:
		return;
	}
}
//�⺻�� 15x15
void basic_map2()
{
		int i, j;
			for(i = 0; i < 15; i++)
		{
			for(j = 0; j < 15; j++)
				printf("��");
			printf("\n");
		}
		
}
void basic_control2(int tx[], int ty[])
{
	char key;
	int i, j, count = 0;
	int x = 1, y = 1;
	int matrix[16][16] = {0};
	do
	{
		gotoxy(x, y);
		matrix[(x + 1) / 2][y] = 1;
		for(i = 0; i < 3; i++)
			if((x + 1) / 2 == tx[i] && (y == ty[i]))
				matrix[(x + 1) / 2][y] = 2;

		gotoxy(1, 1);
		display_basic_map2(matrix,tx,ty);
		gotoxy(x, y);

		if(matrix[(x+1)/2][y]==2)
			printf("��");
		else 
			printf("��");
		count = 0;
		for(i = 1; i <= 15; i++)
			for(j = 1; j <= 15; j++)
				if(matrix[i][j] == 2)
					count += 1;
		gotoxy(1, 20);
		printf("ã�� ����(��)�� ���� : %d", count);
		key = getch();
		move_arrow_key2(key, &x, &y, 29,15);
		}while(count < 3);
}
void make_treasure2(int tx[], int ty[])
{
	int i;
		for(i = 0; i < 3; i ++)
		{
			do{
				tx[i] = rand()%16;
				ty[i] = rand()%16;
			}while((tx[i] < 1) || (ty[i] < 1));
		}
}
void display_basic_map2(int matrix[][16], int tx[], int ty[])
{
	int i, j;
	basic_map2();
	for(i = 1; i <= 15; i++)
		for(j = 1; j <= 15; j++)
			if(matrix[i][j] == 1)
			{
				gotoxy(2 * i - 1, j);
				printf("��");
			}
			else if(matrix[i][j] == 2)
			{
				gotoxy(2 * i - 1, j);
				printf("��");
			}
}
void move_arrow_key2(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
	case 72:
		*y1 = *y1 - 1;
		if(*y1 < 1) *y1 = 1;
		break;
	case 75:
		*x1 = *x1 - 2;
		if(*x1 < 1) *x1 = 1;
		break;
	case 77:
		*x1 = *x1 + 2;
		if(*x1 > x_b) *x1 = x_b;
		break;
	case 80:
		*y1 = *y1 + 1;
		if(*y1 > y_b) *y1 = y_b;
		break;
	default:
		return;
	}
}
//�⺻�� 2020
void basic_map3()
{
		int i, j;
			for(i = 0; i < 20; i++)
		{
			for(j = 0; j < 20; j++)
				printf("��");
			printf("\n");
		}
		
}
void basic_control3(int tx[], int ty[])
{
	char key;
	int i, j, count = 0;
	int x = 1, y = 1;
	int matrix[21][21] = {0};
	do
	{
		gotoxy(x, y);
		matrix[(x + 1) / 2][y] = 1;
		for(i = 0; i < 4; i++)
			if((x + 1) / 2 == tx[i] && (y == ty[i]))
				matrix[(x + 1) / 2][y] = 2;

		gotoxy(1, 1);
		display_basic_map3(matrix,tx,ty);
		gotoxy(x, y);

		if(matrix[(x+1)/2][y]==2)
			printf("��");
		else 
			printf("��");
		count = 0;
		for(i = 1; i <= 20; i++)
			for(j = 1; j <= 20; j++)
				if(matrix[i][j] == 2)
					count += 1;
		gotoxy(1, 40);
		printf("ã�� ����(��)�� ���� : %d", count);
		key = getch();
		move_arrow_key3(key, &x, &y, 39,20);
		}while(count < 3);
}
void make_treasure3(int tx[], int ty[])
{
	int i;
		for(i = 0; i < 4; i ++)
		{
			do{
				tx[i] = rand()%21;
				ty[i] = rand()%21;
			}while((tx[i] < 1) || (ty[i] < 1));
		}
}
void display_basic_map3(int matrix[][21], int tx[], int ty[])
{
	int i, j;
	basic_map3();
	for(i = 1; i <= 20; i++)
		for(j = 1; j <= 20; j++)
			if(matrix[i][j] == 1)
			{
				gotoxy(2 * i - 1, j);
				printf("��");
			}
			else if(matrix[i][j] == 2)
			{
				gotoxy(2 * i - 1, j);
				printf("��");
			}
}
void move_arrow_key3(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
	case 72:
		*y1 = *y1 - 1;
		if(*y1 < 1) *y1 = 1;
		break;
	case 75:
		*x1 = *x1 - 2;
		if(*x1 < 1) *x1 = 1;
		break;
	case 77:
		*x1 = *x1 + 2;
		if(*x1 > x_b) *x1 = x_b;
		break;
	case 80:
		*y1 = *y1 + 1;
		if(*y1 > y_b) *y1 = y_b;
		break;
	default:
		return;
	}
}
// ��ȣ��
void hard_control(int tx[], int ty[])
{
	char key;
	int i, j, count = 0;
	int x = 1, y = 1;
	int matrix[11][11] = {0};
	do
	{
		gotoxy(x, y);
		matrix[(x + 1) / 2][y] = 1;
		for(i = 0; i < 2; i++)
			if((x + 1) / 2 == tx[i] && (y == ty[i]))
				matrix[(x + 1) / 2][y] = 2;

		gotoxy(1, 1);
		display_hard_map(matrix,tx,ty);
		gotoxy(x, y);

		if(matrix[(x+1)/2][y]==2)
			printf("��");
		else 
			printf("��");
		count = 0;
		for(i = 1; i <= 10; i++)
			for(j = 1; j <= 10; j++)
				if(matrix[i][j] == 2)
					count += 1;
		gotoxy(1, 12);
		printf("ã�� ����(��)�� ���� : %d", count);
		key = getch();
		hard_arrow_key(key, &x, &y, 19,10);
		}while(count < 2);
}
void hard_map()
{
	int i, j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if((i<7 && i>2)&&(j>2 && j<7))
					printf("  ");
			else
			printf("��");
		}
		printf("\n");
	}
}
void hard_treasure(int tx[], int ty[])
{
	int i;
		for(i = 0; i < 2; i ++)
		{
			do
			{
				tx[i] = rand()%11;
				ty[i] = rand()%11;
			}while(((tx[i] < 7) && (tx[i]>2)) && ((ty[i] < 7) && (ty[i]>2)));
		}
}
void display_hard_map(int matrix[][11], int tx[], int ty[])
{
	int i, j;
	hard_map();
	for(i = 1; i <= 10; i++)
		for(j = 1; j <= 10; j++)
			 if((i<8 && i>3)&&(j>3 && j<8))
			 {
				 gotoxy(2*i-1,j);
				 printf("  ");
			 }
				else if(matrix[i][j] == 1)
			{
				gotoxy(2 * i - 1, j);
				printf("��");
			}
			else if(matrix[i][j] == 2)
			{
				gotoxy(2 * i - 1, j);
				printf("��");
			}
}
void hard_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
	case 72:
		*y1 = *y1 - 1;
		if(*y1 < 1) *y1 = 1;
		else if((*x1>5&&*x1<15)&&(*y1>3&&*y1<8))
			*y1=*y1+1;
		break;
	case 75:
		*x1 = *x1 - 2;
		if(*x1 < 1) *x1 = 1;
		else if((*x1>5&&*x1<15)&&(*y1>3&&*y1<8))
			*x1 = *x1+2;
		break;
	case 77:
		*x1 = *x1 + 2;
		if(*x1 > x_b) *x1 = x_b;
		else if((*x1>5&&*x1<15)&&(*y1>3&&*y1<8))
			*x1 = *x1-2;
		break;
	case 80:
		*y1 = *y1 + 1;
		if(*y1 > y_b) *y1 = y_b;
		else if((*x1>5&&*x1<15)&&(*y1>3&&*y1<8))
			*y1=*y1-1;
		break;
	default:
		return;
	}
}
//�����̸�
void sample_Dowon_map(void)
{
	int i;
		for(i=0;i<10;i++)
			printf("��");
		printf("\n");
	printf("��  ���  ���  ���\n");
		for(i=0;i<10;i++)
			printf("��");
		printf("\n");
		printf("��  ���  ���  ���\n");
		for(i=0;i<10;i++)
			printf("��");
		printf("\n");
		printf("��  ���  ���  ���\n");
		for(i=0;i<10;i++)
			printf("��");
		printf("\n");
		printf("��  ���  ���  ���\n");
			for(i=0;i<10;i++)
			printf("��");
		printf("\n");
		printf("��  ���  ���  ���\n");
}
void Dowon_map(void)
{
	int i, j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			printf("��");
		printf("\n");
	}
	gotoxy(3, 2);
	printf(" ");
	gotoxy(9, 2);
	printf(" ");
	gotoxy(15, 2);
	printf(" ");
	gotoxy(21, 2);
	printf(" ");
	gotoxy(27, 2);
	printf(" ");
	
	gotoxy(3, 4);
	printf(" ");
	gotoxy(9, 4);
	printf(" ");
	gotoxy(15, 4);
	printf(" ");
	gotoxy(21, 4);
	printf(" ");
	gotoxy(27, 4);
	printf(" ");


	gotoxy(3, 6);
	printf(" ");
	gotoxy(9, 6);
	printf(" ");
	gotoxy(15, 6);
	printf(" ");
	gotoxy(21, 6);
	printf(" ");
	gotoxy(27, 6);
	printf(" ");

	gotoxy(3, 8);
	printf(" ");
	gotoxy(9, 8);
	printf(" ");
	gotoxy(15, 8);
	printf(" ");
	gotoxy(21, 8);
	printf(" ");
	gotoxy(27, 8);
	printf(" ");


	gotoxy(3, 10);
	printf(" ");
	gotoxy(9, 10);
	printf(" ");
	gotoxy(15, 10);
	printf(" ");
	gotoxy(21, 10);
	printf(" ");
	gotoxy(27, 10);
	printf(" ");


	gotoxy(3, 12);
	printf(" ");
	gotoxy(9, 12);
	printf(" ");
	gotoxy(15, 12);
	printf(" ");
	gotoxy(21, 12);
	printf(" ");
	gotoxy(27, 12);
	printf(" ");
	
}
void Dowon_MakeTreasure(int tx[], int ty[])
{
	int i;
	for(i=0;i<2;i++)
	{
		do
		{
			tx[i]=rand()%11;
			ty[i]=rand()%11;
		}while(((tx[i]<=0) || (ty[i]<=0))&&
			(((tx[i]==2&&ty[i]==2)||
			  (tx[i]==5&&ty[i]==2)||
			  (tx[i]==8&&ty[i]==2)||
			  (tx[i]==2&&ty[i]==4)||
			  (tx[i]==5&&ty[i]==4)||
			  (tx[i]==8&&ty[i]==4)||
			  (tx[i]==2&&ty[i]==6)||
			  (tx[i]==5&&ty[i]==6)||
			  (tx[i]==8&&ty[i]==6)||
			  (tx[i]==2&&ty[i]==8)||
			  (tx[i]==5&&ty[i]==8)||
			  (tx[i]==8&&ty[i]==8)))); 
	}
}
void Dowon_display_map(int matrix[][11], int tx[], int ty[]) // ���� ��������
{
	int i, j;
	Dowon_map();
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			if(matrix[i][j]==-1)
			{
				gotoxy(2*i-1, j);
				printf("��");
			}
			else if(matrix[i][j]==2)
			{
				gotoxy(2*i-1, j);
				printf("��");
			}
			else if(matrix[i][j]==-2)
			{
				gotoxy(2*i-1, j);
				printf("��");
			}

}
void Dowon_game(int tx[], int ty[]) // ���� ���� �Լ�
{
	char key;
	int i, j, count = 0;
	int x=1, y=1;
	int matrix[11][11]={0};
	system("cls");
	while(count<2)
	{
		for(j=2;j<10;j=j+2)
		for(i=2;i<10;i=i+3)
		{
			matrix[i][j]=-4;
		}
		gotoxy(x, y);
		matrix[(x+1)/2][y]=-2;

		for(i=0;i<2;i++)
			if(((x+1)/2==tx[i])&&(y==ty[i]))
				matrix[(x+1)/2][y]=2;

		gotoxy(1, 1);
		Dowon_display_map(matrix, tx, ty);

		if(matrix[(x+1)/2][y]!=2)
		{
			matrix[(x+1)/2][y]=-1;
		}
		
		count=0;
		for(i=1;i<=10;i++)
			for(j=1;j<=10;j++)
				if(matrix[i][j]==2)
					count+=1;
		
		key=getch();
		Dowon_arrow_key(key, &x, &y, 19, 10);
		
	}
}
void Dowon_arrow_key(char key, int* x1,int *y1, int x_b, int y_b)
{
	int i=0, j=0;
	switch(key)
	{
	case 72:
		*y1=*y1-1;
		if(*y1<1) *y1=1;

		else
		{
			if((*x1==3&&*y1==2)||
			   (*x1==3&&*y1==4)||
			   (*x1==3&&*y1==6)||
			   (*x1==3&&*y1==8)||
			   (*x1==3&&*y1==10)||
			   (*x1==9&&*y1==2)||
			   (*x1==9&&*y1==4)||
			   (*x1==9&&*y1==6)||
			   (*x1==9&&*y1==8)||
			   (*x1==9&&*y1==10)||
			   (*x1==15&&*y1==2)||
			   (*x1==15&&*y1==4)||
			   (*x1==15&&*y1==6)||
			   (*x1==15&&*y1==8)||
			   (*x1==15&&*y1==10))
			   *y1=*y1+1;
		}
		break;
	case 75:
		*x1=*x1-2;
		if(*x1<1) *x1=1;
		else
		{
			if((*x1==3&&*y1==2)||
			   (*x1==3&&*y1==4)||
			   (*x1==3&&*y1==6)||
			   (*x1==3&&*y1==8)||
			   (*x1==3&&*y1==10)||
			   (*x1==9&&*y1==2)||
			   (*x1==9&&*y1==4)||
			   (*x1==9&&*y1==6)||
			   (*x1==9&&*y1==8)||
			   (*x1==9&&*y1==10)||
			   (*x1==15&&*y1==2)||
			   (*x1==15&&*y1==4)||
			   (*x1==15&&*y1==6)||
			   (*x1==15&&*y1==8)||
			   (*x1==15&&*y1==10))
			   *x1=*x1+2;
		}
			
		break;
	case 77:
		*x1=*x1+2;
		if(*x1>x_b) *x1=x_b;
				
		else
		{
			if((*x1==3&&*y1==2)||
			   (*x1==3&&*y1==4)||
			   (*x1==3&&*y1==6)||
			   (*x1==3&&*y1==8)||
			   (*x1==3&&*y1==10)||
			   (*x1==9&&*y1==2)||
			   (*x1==9&&*y1==4)||
			   (*x1==9&&*y1==6)||
			   (*x1==9&&*y1==8)||
			   (*x1==9&&*y1==10)||
			   (*x1==15&&*y1==2)||
			   (*x1==15&&*y1==4)||
			   (*x1==15&&*y1==6)||
			   (*x1==15&&*y1==8)||
			   (*x1==15&&*y1==10))
			   *x1=*x1-2;
		}

		break;
	case 80:
		*y1=*y1+1;
		if(*y1>y_b) *y1=y_b;
		else
		{
		
			if((*x1==3&&*y1==2)||
			   (*x1==3&&*y1==4)||
			   (*x1==3&&*y1==6)||
			   (*x1==3&&*y1==8)||
			   (*x1==3&&*y1==10)||
			   (*x1==9&&*y1==2)||
			   (*x1==9&&*y1==4)||
			   (*x1==9&&*y1==6)||
			   (*x1==9&&*y1==8)||
			   (*x1==9&&*y1==10)||
			   (*x1==15&&*y1==2)||
			   (*x1==15&&*y1==4)||
			   (*x1==15&&*y1==6)||
			   (*x1==15&&*y1==8)||
			   (*x1==15&&*y1==10))
			   *y1=*y1-1;
		}
		
		
		break;
	default:
		return;
	}
}
////////////////////////////////////////////////////////////////////////////
void Dowon_map2(void)
{
	int i, j;
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
			printf("��");
		printf("\n");
	}
	gotoxy(3, 2);
	printf(" ");
	gotoxy(9, 2);
	printf(" ");
	gotoxy(15, 2);
	printf(" ");
	gotoxy(21, 2);
	printf(" ");
	gotoxy(27, 2);
	printf(" ");

	gotoxy(3, 4);
	printf(" ");
	gotoxy(9, 4);
	printf(" ");
	gotoxy(15, 4);
	printf(" ");
	gotoxy(21, 4);
	printf(" ");
	gotoxy(27, 4);
	printf(" ");

	gotoxy(3, 6);
	printf(" ");
	gotoxy(9, 6);
	printf(" ");
	gotoxy(15, 6);
	printf(" ");
	gotoxy(21, 6);
	printf(" ");
	gotoxy(27, 6);
	printf(" ");

	gotoxy(3, 8);
	printf(" ");
	gotoxy(9, 8);
	printf(" ");
	gotoxy(15, 8);
	printf(" ");
	gotoxy(21, 8);
	printf(" ");
	gotoxy(27, 8);
	printf(" ");

	gotoxy(3, 10);
	printf(" ");
	gotoxy(9, 10);
	printf(" ");
	gotoxy(15, 10);
	printf(" ");
	gotoxy(21, 10);
	printf(" ");
	gotoxy(27, 10);
	printf(" ");

	gotoxy(3, 12);
	printf(" ");
	gotoxy(9, 12);
	printf(" ");
	gotoxy(15, 12);
	printf(" ");
	gotoxy(21, 12);
	printf(" ");
	gotoxy(27, 12);
	printf(" ");

	gotoxy(3, 14);
	printf(" ");
	gotoxy(9, 14);
	printf(" ");
	gotoxy(15, 14);
	printf(" ");
	gotoxy(21, 14);
	printf(" ");
	gotoxy(27, 14);
	printf(" ");

	gotoxy(3, 16);
	printf(" ");
	gotoxy(9, 16);
	printf(" ");
	gotoxy(15, 16);
	printf(" ");
	gotoxy(21, 16);
	printf(" ");
	gotoxy(27, 16);
	printf(" ");
	
}
void Dowon_MakeTreasure2(int tx[], int ty[])
{
	int i;
	for(i=0;i<3;i++)
	{
		do
		{
			tx[i]=rand()%16;
			ty[i]=rand()%16;
		}while(((tx[i]<=0) || (ty[i]<=0))&&
			(((tx[i]==2&&ty[i]==2)||
			  (tx[i]==5&&ty[i]==2)||
			  (tx[i]==8&&ty[i]==2)||
			  (tx[i]==11&&ty[i]==2)||
			  (tx[i]==14&&ty[i]==2)||

			  (tx[i]==2&&ty[i]==4)||
			  (tx[i]==5&&ty[i]==4)||
			  (tx[i]==8&&ty[i]==4)||
			  (tx[i]==11&&ty[i]==4)||
			  (tx[i]==14&&ty[i]==4)||

			  (tx[i]==2&&ty[i]==6)||
			  (tx[i]==5&&ty[i]==6)||
			  (tx[i]==8&&ty[i]==6)||
			  (tx[i]==11&&ty[i]==6)||
			  (tx[i]==14&&ty[i]==6)||


			  (tx[i]==2&&ty[i]==8)||
			  (tx[i]==5&&ty[i]==8)||
			  (tx[i]==8&&ty[i]==8)||
			  (tx[i]==11&&ty[i]==8)||
			  (tx[i]==14&&ty[i]==8)||


			  (tx[i]==2&&ty[i]==10)||
			  (tx[i]==5&&ty[i]==10)||
			  (tx[i]==8&&ty[i]==10)||
			  (tx[i]==11&&ty[i]==10)||
			  (tx[i]==14&&ty[i]==10)||


			  (tx[i]==2&&ty[i]==12)||
			  (tx[i]==5&&ty[i]==12)||
			  (tx[i]==8&&ty[i]==12)||
			  (tx[i]==11&&ty[i]==12)||
			  (tx[i]==14&&ty[i]==12)||


			  (tx[i]==11&&ty[i]==14)||
			  (tx[i]==14&&ty[i]==14)||
			  (tx[i]==2&&ty[i]==14)||
			  (tx[i]==5&&ty[i]==14)||
			  (tx[i]==8&&ty[i]==14)))); 
	}
}
void Dowon_display_map2(int matrix[][16], int tx[], int ty[]) // ���� ��������
{
	int i, j;
	Dowon_map2();
	for(i=1;i<=15;i++)
		for(j=1;j<=15;j++)
			if(matrix[i][j]==-1)
			{
				gotoxy(2*i-1, j);
				printf("��");
			}
			else if(matrix[i][j]==2)
			{
				gotoxy(2*i-1, j);
				printf("��");
			}
			else if(matrix[i][j]==-2)
			{
				gotoxy(2*i-1, j);
				printf("��");
			}

}
void Dowon_game2(int tx[], int ty[]) // ���� ���� �Լ�
{
	char key;
	int i, j, count = 0;
	int x=1, y=1;
	int matrix[16][16]={0};
	system("cls");
	while(count<2)
	{
		for(j=2;j<15;j=j+2)
		for(i=2;i<15;i=i+3)
		{
			matrix[i][j]=-4;
		}
		gotoxy(x, y);
		matrix[(x+1)/2][y]=-2;

		for(i=0;i<2;i++)
			if(((x+1)/2==tx[i])&&(y==ty[i]))
				matrix[(x+1)/2][y]=2;

		gotoxy(1, 1);
		Dowon_display_map2(matrix, tx, ty);

		if(matrix[(x+1)/2][y]!=2)
		{
			matrix[(x+1)/2][y]=-1;
		}
		
		count=0;
		for(i=1;i<=10;i++)
			for(j=1;j<=10;j++)
				if(matrix[i][j]==2)
					count+=1;
	
		key=getch();
		Dowon_arrow_key2(key, &x, &y, 30, 15);
		
	}
}
void Dowon_arrow_key2(char key, int* x1,int *y1, int x_b, int y_b)
{
	int i=0, j=0;
	switch(key)
	{
	case 72:
		*y1=*y1-1;
		if(*y1<1) *y1=1;

		else
		{
			if((*x1==3&&*y1==2)||
			   (*x1==3&&*y1==4)||
			   (*x1==3&&*y1==6)||
			   (*x1==3&&*y1==8)||
			   (*x1==3&&*y1==10)||
			   (*x1==3&&*y1==12)||
			   (*x1==3&&*y1==14)||

			   (*x1==9&&*y1==2)||
			   (*x1==9&&*y1==4)||
			   (*x1==9&&*y1==6)||
			   (*x1==9&&*y1==8)||
			   (*x1==9&&*y1==10)||
			   (*x1==9&&*y1==12)||
			   (*x1==9&&*y1==14)||

			   (*x1==15&&*y1==2)||
			   (*x1==15&&*y1==4)||
			   (*x1==15&&*y1==6)||
			   (*x1==15&&*y1==8)||
			   (*x1==15&&*y1==10)||
			   (*x1==15&&*y1==12)||
			   (*x1==15&&*y1==14)||

			   (*x1==21&&*y1==2)||
			   (*x1==21&&*y1==4)||
			   (*x1==21&&*y1==6)||
			   (*x1==21&&*y1==8)||
			   (*x1==21&&*y1==10)||
			   (*x1==21&&*y1==12)||
			   (*x1==21&&*y1==14)||

			   (*x1==27&&*y1==2)||
			   (*x1==27&&*y1==4)||
			   (*x1==27&&*y1==6)||
			   (*x1==27&&*y1==8)||
			   (*x1==27&&*y1==10)||
			   (*x1==27&&*y1==12)||
			   (*x1==27&&*y1==14))
			   *y1=*y1+1;
		}
		break;
	case 75:
		*x1=*x1-2;
		if(*x1<1) *x1=1;
		else
		{
			if((*x1==3&&*y1==2)||
			   (*x1==3&&*y1==4)||
			   (*x1==3&&*y1==6)||
			   (*x1==3&&*y1==8)||
			   (*x1==3&&*y1==10)||
			   (*x1==3&&*y1==12)||
			   (*x1==3&&*y1==14)||

			   (*x1==9&&*y1==2)||
			   (*x1==9&&*y1==4)||
			   (*x1==9&&*y1==6)||
			   (*x1==9&&*y1==8)||
			   (*x1==9&&*y1==10)||
			   (*x1==9&&*y1==12)||
			   (*x1==9&&*y1==14)||

			   (*x1==15&&*y1==2)||
			   (*x1==15&&*y1==4)||
			   (*x1==15&&*y1==6)||
			   (*x1==15&&*y1==8)||
			   (*x1==15&&*y1==10)||
			   (*x1==15&&*y1==12)||
			   (*x1==15&&*y1==14)||

			   (*x1==21&&*y1==2)||
			   (*x1==21&&*y1==4)||
			   (*x1==21&&*y1==6)||
			   (*x1==21&&*y1==8)||
			   (*x1==21&&*y1==10)||
			   (*x1==21&&*y1==12)||
			   (*x1==21&&*y1==14)||

			   (*x1==27&&*y1==2)||
			   (*x1==27&&*y1==4)||
			   (*x1==27&&*y1==6)||
			   (*x1==27&&*y1==8)||
			   (*x1==27&&*y1==10)||
			   (*x1==27&&*y1==12)||
			   (*x1==27&&*y1==14))
			   *x1=*x1+2;
		}
			
		break;
	case 77:
		*x1=*x1+2;
		if(*x1>x_b) *x1=x_b;
				
		else
		{
			if((*x1==3&&*y1==2)||
			   (*x1==3&&*y1==4)||
			   (*x1==3&&*y1==6)||
			   (*x1==3&&*y1==8)||
			   (*x1==3&&*y1==10)||
			   (*x1==3&&*y1==12)||
			   (*x1==3&&*y1==14)||

			   (*x1==9&&*y1==2)||
			   (*x1==9&&*y1==4)||
			   (*x1==9&&*y1==6)||
			   (*x1==9&&*y1==8)||
			   (*x1==9&&*y1==10)||
			   (*x1==9&&*y1==12)||
			   (*x1==9&&*y1==14)||

			   (*x1==15&&*y1==2)||
			   (*x1==15&&*y1==4)||
			   (*x1==15&&*y1==6)||
			   (*x1==15&&*y1==8)||
			   (*x1==15&&*y1==10)||
			   (*x1==15&&*y1==12)||
			   (*x1==15&&*y1==14)||

			   (*x1==21&&*y1==2)||
			   (*x1==21&&*y1==4)||
			   (*x1==21&&*y1==6)||
			   (*x1==21&&*y1==8)||
			   (*x1==21&&*y1==10)||
			   (*x1==21&&*y1==12)||
			   (*x1==21&&*y1==14)||

			   (*x1==27&&*y1==2)||
			   (*x1==27&&*y1==4)||
			   (*x1==27&&*y1==6)||
			   (*x1==27&&*y1==8)||
			   (*x1==27&&*y1==10)||
			   (*x1==27&&*y1==12)||
			   (*x1==27&&*y1==14))
			   *x1=*x1-2;
		}

		break;
	case 80:
		*y1=*y1+1;
		if(*y1>y_b) *y1=y_b;
		else
		{
		
			if((*x1==3&&*y1==2)||
			   (*x1==3&&*y1==4)||
			   (*x1==3&&*y1==6)||
			   (*x1==3&&*y1==8)||
			   (*x1==3&&*y1==10)||
			   (*x1==3&&*y1==12)||
			   (*x1==3&&*y1==14)||

			   (*x1==9&&*y1==2)||
			   (*x1==9&&*y1==4)||
			   (*x1==9&&*y1==6)||
			   (*x1==9&&*y1==8)||
			   (*x1==9&&*y1==10)||
			   (*x1==9&&*y1==12)||
			   (*x1==9&&*y1==14)||

			   (*x1==15&&*y1==2)||
			   (*x1==15&&*y1==4)||
			   (*x1==15&&*y1==6)||
			   (*x1==15&&*y1==8)||
			   (*x1==15&&*y1==10)||
			   (*x1==15&&*y1==12)||
			   (*x1==15&&*y1==14)||

			   (*x1==21&&*y1==2)||
			   (*x1==21&&*y1==4)||
			   (*x1==21&&*y1==6)||
			   (*x1==21&&*y1==8)||
			   (*x1==21&&*y1==10)||
			   (*x1==21&&*y1==12)||
			   (*x1==21&&*y1==14)||

			   (*x1==27&&*y1==2)||
			   (*x1==27&&*y1==4)||
			   (*x1==27&&*y1==6)||
			   (*x1==27&&*y1==8)||
			   (*x1==27&&*y1==10)||
			   (*x1==27&&*y1==12)||
			   (*x1==27&&*y1==14))
			   *y1=*y1-1;
		}
		
		
		break;
	default:
		return;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void Dowon_map3(void)
{
	int i, j;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
			printf("��");
		printf("\n");
	}
	gotoxy(3, 2);
	printf(" ");
	gotoxy(9, 2);
	printf(" ");
	gotoxy(15, 2);
	printf(" ");
	gotoxy(21, 2);
	printf(" ");
	gotoxy(27, 2);
	printf(" ");
	gotoxy(33, 2);
	printf(" ");
	gotoxy(39, 2);
	printf(" ");


	gotoxy(3, 4);
	printf(" ");
	gotoxy(9, 4);
	printf(" ");
	gotoxy(15, 4);
	printf(" ");
	gotoxy(21, 4);
	printf(" ");
	gotoxy(27, 4);
	printf(" ");
	gotoxy(33, 4);
	printf(" ");
	gotoxy(39, 4);
	printf(" ");


	gotoxy(3, 6);
	printf(" ");
	gotoxy(9, 6);
	printf(" ");
	gotoxy(15, 6);
	printf(" ");
	gotoxy(21, 6);
	printf(" ");
	gotoxy(27, 6);
	printf(" ");
	gotoxy(33, 6);
	printf(" ");
	gotoxy(39, 6);
	printf(" ");


	gotoxy(3, 8);
	printf(" ");
	gotoxy(9, 8);
	printf(" ");
	gotoxy(15, 8);
	printf(" ");
	gotoxy(21, 8);
	printf(" ");
	gotoxy(27, 8);
	printf(" ");
	gotoxy(33, 8);
	printf(" ");
	gotoxy(39, 8);
	printf(" ");


	gotoxy(3, 10);
	printf(" ");
	gotoxy(9, 10);
	printf(" ");
	gotoxy(15, 10);
	printf(" ");
	gotoxy(21, 10);
	printf(" ");
	gotoxy(27, 10);
	printf(" ");
	gotoxy(33, 10);
	printf(" ");
	gotoxy(39, 10);
	printf(" ");


	gotoxy(3, 12);
	printf(" ");
	gotoxy(9, 12);
	printf(" ");
	gotoxy(15, 12);
	printf(" ");
	gotoxy(21, 12);
	printf(" ");
	gotoxy(27, 12);
	printf(" ");
	gotoxy(33, 12);
	printf(" ");
	gotoxy(39, 12);
	printf(" ");


	gotoxy(3, 14);
	printf(" ");
	gotoxy(9, 14);
	printf(" ");
	gotoxy(15, 14);
	printf(" ");
	gotoxy(21, 14);
	printf(" ");
	gotoxy(27, 14);
	printf(" ");
	gotoxy(33, 14);
	printf(" ");
	gotoxy(39, 14);
	printf(" ");


	gotoxy(3, 16);
	printf(" ");
	gotoxy(9, 16);
	printf(" ");
	gotoxy(15, 16);
	printf(" ");
	gotoxy(21, 16);
	printf(" ");
	gotoxy(27, 16);
	printf(" ");
	gotoxy(33, 16);
	printf(" ");
	gotoxy(39, 16);
	printf(" ");


	gotoxy(3, 18);
	printf(" ");
	gotoxy(9, 18);
	printf(" ");
	gotoxy(15, 18);
	printf(" ");
	gotoxy(21, 18);
	printf(" ");
	gotoxy(27, 18);
	printf(" ");
	gotoxy(33, 18);
	printf(" ");
	gotoxy(39, 18);
	printf(" ");


	gotoxy(3, 20);
	printf(" ");
	gotoxy(9, 20);
	printf(" ");
	gotoxy(15, 20);
	printf(" ");
	gotoxy(21, 20);
	printf(" ");
	gotoxy(27, 20);
	printf(" ");
	gotoxy(33, 20);
	printf(" ");
	gotoxy(39, 20);
	printf(" ");

	gotoxy(3, 22);
	printf(" ");
	gotoxy(9, 22);
	printf(" ");
	gotoxy(15, 22);
	printf(" ");
	gotoxy(21, 22);
	printf(" ");
	gotoxy(27, 22);
	printf(" ");
	gotoxy(33, 22);
	printf(" ");
	gotoxy(39, 22);
	printf(" ");

	
}
void Dowon_MakeTreasure3(int tx[], int ty[])
{
	int i;
	for(i=0;i<2;i++)
	{
		do
		{
			tx[i]=rand()%11;
			ty[i]=rand()%11;
		}while(((tx[i]<=0) || (ty[i]<=0))&&
			(((tx[i]==2&&ty[i]==2)||
			  (tx[i]==5&&ty[i]==2)||
			  (tx[i]==8&&ty[i]==2)||
			  (tx[i]==11&&ty[i]==2)||
			  (tx[i]==14&&ty[i]==2)||

			  (tx[i]==2&&ty[i]==4)||
			  (tx[i]==5&&ty[i]==4)||
			  (tx[i]==8&&ty[i]==4)||
			  (tx[i]==11&&ty[i]==4)||
			  (tx[i]==14&&ty[i]==4)||

			  (tx[i]==2&&ty[i]==6)||
			  (tx[i]==5&&ty[i]==6)||
			  (tx[i]==8&&ty[i]==6)||
			  (tx[i]==11&&ty[i]==6)||
			  (tx[i]==14&&ty[i]==6)||


			  (tx[i]==2&&ty[i]==8)||
			  (tx[i]==5&&ty[i]==8)||
			  (tx[i]==8&&ty[i]==8)||
			  (tx[i]==11&&ty[i]==8)||
			  (tx[i]==14&&ty[i]==8)||


			  (tx[i]==2&&ty[i]==10)||
			  (tx[i]==5&&ty[i]==10)||
			  (tx[i]==8&&ty[i]==10)||
			  (tx[i]==11&&ty[i]==10)||
			  (tx[i]==14&&ty[i]==10)||


			  (tx[i]==2&&ty[i]==12)||
			  (tx[i]==5&&ty[i]==12)||
			  (tx[i]==8&&ty[i]==12)||
			  (tx[i]==11&&ty[i]==12)||
			  (tx[i]==14&&ty[i]==12)||


			  (tx[i]==11&&ty[i]==14)||
			  (tx[i]==14&&ty[i]==14)||
			  (tx[i]==2&&ty[i]==14)||
			  (tx[i]==5&&ty[i]==14)||
			  (tx[i]==8&&ty[i]==14)))); 
	}
}
void Dowon_display_map3(int matrix[][21], int tx[], int ty[]) // ���� ��������
{
	int i, j;
	Dowon_map3();
	for(i=1;i<=20;i++)
		for(j=1;j<=20;j++)
			if(matrix[i][j]==-1)
			{
				gotoxy(2*i-1, j);
				printf("��");
			}
			else if(matrix[i][j]==2)
			{
				gotoxy(2*i-1, j);
				printf("��");
			}
			else if(matrix[i][j]==-2)
			{
				gotoxy(2*i-1, j);
				printf("��");
			}

}
void Dowon_game3(int tx[], int ty[]) // ���� ���� �Լ�
{
	char key;
	int i, j, count = 0;
	int x=1, y=1;
	int matrix[21][21]={0};
	system("cls");
	while(count<2)
	{
		for(j=2;j<20;j=j+2)
		for(i=2;i<20;i=i+3)
		{
			matrix[i][j]=-4;
		}
		gotoxy(x, y);
		matrix[(x+1)/2][y]=-2;

		for(i=0;i<2;i++)
			if(((x+1)/2==tx[i])&&(y==ty[i]))
				matrix[(x+1)/2][y]=2;

		gotoxy(1, 1);
		Dowon_display_map3(matrix, tx, ty);

		if(matrix[(x+1)/2][y]!=2)
		{
			matrix[(x+1)/2][y]=-1;
		}
		
		count=0;
		for(i=1;i<=10;i++)
			for(j=1;j<=10;j++)
				if(matrix[i][j]==2)
					count+=1;
	
		key=getch();
		Dowon_arrow_key3(key, &x, &y, 40, 20);
		
	}
}
void Dowon_arrow_key3(char key, int* x1,int *y1, int x_b, int y_b)
{
	int i=0, j=0;
	switch(key)
	{
	case 72:
		*y1=*y1-1;
		if(*y1<1) *y1=1;

		else
		{
			if((*x1==3&&*y1==2)||
			   (*x1==3&&*y1==4)||
			   (*x1==3&&*y1==6)||
			   (*x1==3&&*y1==8)||
			   (*x1==3&&*y1==10)||
			   (*x1==3&&*y1==12)||
			   (*x1==3&&*y1==14)||
			   (*x1==3&&*y1==16)||
			   (*x1==3&&*y1==18)||
			   (*x1==3&&*y1==20)||

			   (*x1==9&&*y1==2)||
			   (*x1==9&&*y1==4)||
			   (*x1==9&&*y1==6)||
			   (*x1==9&&*y1==8)||
			   (*x1==9&&*y1==10)||
			   (*x1==9&&*y1==12)||
			   (*x1==9&&*y1==14)||
			   (*x1==9&&*y1==16)||
			   (*x1==9&&*y1==18)||
			   (*x1==9&&*y1==20)||

			   (*x1==15&&*y1==2)||
			   (*x1==15&&*y1==4)||
			   (*x1==15&&*y1==6)||
			   (*x1==15&&*y1==8)||
			   (*x1==15&&*y1==10)||
			   (*x1==15&&*y1==12)||
			   (*x1==15&&*y1==14)||
			   (*x1==15&&*y1==16)||
			   (*x1==15&&*y1==18)||
			   (*x1==15&&*y1==20)||

			   (*x1==21&&*y1==2)||
			   (*x1==21&&*y1==4)||
			   (*x1==21&&*y1==6)||
			   (*x1==21&&*y1==8)||
			   (*x1==21&&*y1==10)||
			   (*x1==21&&*y1==12)||
			   (*x1==21&&*y1==14)||
			   (*x1==21&&*y1==16)||
			   (*x1==21&&*y1==18)||
			   (*x1==21&&*y1==20)||

			   (*x1==27&&*y1==2)||
			   (*x1==27&&*y1==4)||
			   (*x1==27&&*y1==6)||
			   (*x1==27&&*y1==8)||
			   (*x1==27&&*y1==10)||
			   (*x1==27&&*y1==12)||
			   (*x1==27&&*y1==14)||
			   (*x1==27&&*y1==16)||
			   (*x1==27&&*y1==18)||
			   (*x1==27&&*y1==20)||

			   (*x1==33&&*y1==2)||
			   (*x1==33&&*y1==4)||
			   (*x1==33&&*y1==6)||
			   (*x1==33&&*y1==8)||
			   (*x1==33&&*y1==10)||
			   (*x1==33&&*y1==12)||
			   (*x1==33&&*y1==14)||
			   (*x1==33&&*y1==16)||
			   (*x1==33&&*y1==18)||
			   (*x1==33&&*y1==20)||

			   (*x1==39&&*y1==2)||
			   (*x1==39&&*y1==4)||
			   (*x1==39&&*y1==6)||
			   (*x1==39&&*y1==8)||
			   (*x1==39&&*y1==10)||
			   (*x1==39&&*y1==12)||
			   (*x1==39&&*y1==14)||
			   (*x1==39&&*y1==16)||
			   (*x1==39&&*y1==18)||
			   (*x1==39&&*y1==20))
			   *y1=*y1+1;
		}
		break;
	case 75:
		*x1=*x1-2;
		if(*x1<1) *x1=1;
		else
		{
			if((*x1==3&&*y1==2)||
			   (*x1==3&&*y1==4)||
			   (*x1==3&&*y1==6)||
			   (*x1==3&&*y1==8)||
			   (*x1==3&&*y1==10)||
			   (*x1==3&&*y1==12)||
			   (*x1==3&&*y1==14)||
			   (*x1==3&&*y1==16)||
			   (*x1==3&&*y1==18)||
			   (*x1==3&&*y1==20)||

			   (*x1==9&&*y1==2)||
			   (*x1==9&&*y1==4)||
			   (*x1==9&&*y1==6)||
			   (*x1==9&&*y1==8)||
			   (*x1==9&&*y1==10)||
			   (*x1==9&&*y1==12)||
			   (*x1==9&&*y1==14)||
			   (*x1==9&&*y1==16)||
			   (*x1==9&&*y1==18)||
			   (*x1==9&&*y1==20)||

			   (*x1==15&&*y1==2)||
			   (*x1==15&&*y1==4)||
			   (*x1==15&&*y1==6)||
			   (*x1==15&&*y1==8)||
			   (*x1==15&&*y1==10)||
			   (*x1==15&&*y1==12)||
			   (*x1==15&&*y1==14)||
			   (*x1==15&&*y1==16)||
			   (*x1==15&&*y1==18)||
			   (*x1==15&&*y1==20)||

			   (*x1==21&&*y1==2)||
			   (*x1==21&&*y1==4)||
			   (*x1==21&&*y1==6)||
			   (*x1==21&&*y1==8)||
			   (*x1==21&&*y1==10)||
			   (*x1==21&&*y1==12)||
			   (*x1==21&&*y1==14)||
			   (*x1==21&&*y1==16)||
			   (*x1==21&&*y1==18)||
			   (*x1==21&&*y1==20)||

			   (*x1==27&&*y1==2)||
			   (*x1==27&&*y1==4)||
			   (*x1==27&&*y1==6)||
			   (*x1==27&&*y1==8)||
			   (*x1==27&&*y1==10)||
			   (*x1==27&&*y1==12)||
			   (*x1==27&&*y1==14)||
			   (*x1==27&&*y1==16)||
			   (*x1==27&&*y1==18)||
			   (*x1==27&&*y1==20)||

			   (*x1==33&&*y1==2)||
			   (*x1==33&&*y1==4)||
			   (*x1==33&&*y1==6)||
			   (*x1==33&&*y1==8)||
			   (*x1==33&&*y1==10)||
			   (*x1==33&&*y1==12)||
			   (*x1==33&&*y1==14)||
			   (*x1==33&&*y1==16)||
			   (*x1==33&&*y1==18)||
			   (*x1==33&&*y1==20)||

			   (*x1==39&&*y1==2)||
			   (*x1==39&&*y1==4)||
			   (*x1==39&&*y1==6)||
			   (*x1==39&&*y1==8)||
			   (*x1==39&&*y1==10)||
			   (*x1==39&&*y1==12)||
			   (*x1==39&&*y1==14)||
			   (*x1==39&&*y1==16)||
			   (*x1==39&&*y1==18)||
			   (*x1==39&&*y1==20))
			   *x1=*x1+2;
		}
			
		break;
	case 77:
		*x1=*x1+2;
		if(*x1>x_b) *x1=x_b;
				
		else
		{
			if((*x1==3&&*y1==2)||
			   (*x1==3&&*y1==4)||
			   (*x1==3&&*y1==6)||
			   (*x1==3&&*y1==8)||
			   (*x1==3&&*y1==10)||
			   (*x1==3&&*y1==12)||
			   (*x1==3&&*y1==14)||
			   (*x1==3&&*y1==16)||
			   (*x1==3&&*y1==18)||
			   (*x1==3&&*y1==20)||

			   (*x1==9&&*y1==2)||
			   (*x1==9&&*y1==4)||
			   (*x1==9&&*y1==6)||
			   (*x1==9&&*y1==8)||
			   (*x1==9&&*y1==10)||
			   (*x1==9&&*y1==12)||
			   (*x1==9&&*y1==14)||
			   (*x1==9&&*y1==16)||
			   (*x1==9&&*y1==18)||
			   (*x1==9&&*y1==20)||

			   (*x1==15&&*y1==2)||
			   (*x1==15&&*y1==4)||
			   (*x1==15&&*y1==6)||
			   (*x1==15&&*y1==8)||
			   (*x1==15&&*y1==10)||
			   (*x1==15&&*y1==12)||
			   (*x1==15&&*y1==14)||
			   (*x1==15&&*y1==16)||
			   (*x1==15&&*y1==18)||
			   (*x1==15&&*y1==20)||

			   (*x1==21&&*y1==2)||
			   (*x1==21&&*y1==4)||
			   (*x1==21&&*y1==6)||
			   (*x1==21&&*y1==8)||
			   (*x1==21&&*y1==10)||
			   (*x1==21&&*y1==12)||
			   (*x1==21&&*y1==14)||
			   (*x1==21&&*y1==16)||
			   (*x1==21&&*y1==18)||
			   (*x1==21&&*y1==20)||

			   (*x1==27&&*y1==2)||
			   (*x1==27&&*y1==4)||
			   (*x1==27&&*y1==6)||
			   (*x1==27&&*y1==8)||
			   (*x1==27&&*y1==10)||
			   (*x1==27&&*y1==12)||
			   (*x1==27&&*y1==14)||
			   (*x1==27&&*y1==16)||
			   (*x1==27&&*y1==18)||
			   (*x1==27&&*y1==20)||

			   (*x1==33&&*y1==2)||
			   (*x1==33&&*y1==4)||
			   (*x1==33&&*y1==6)||
			   (*x1==33&&*y1==8)||
			   (*x1==33&&*y1==10)||
			   (*x1==33&&*y1==12)||
			   (*x1==33&&*y1==14)||
			   (*x1==33&&*y1==16)||
			   (*x1==33&&*y1==18)||
			   (*x1==33&&*y1==20)||

			   (*x1==39&&*y1==2)||
			   (*x1==39&&*y1==4)||
			   (*x1==39&&*y1==6)||
			   (*x1==39&&*y1==8)||
			   (*x1==39&&*y1==10)||
			   (*x1==39&&*y1==12)||
			   (*x1==39&&*y1==14)||
			   (*x1==39&&*y1==16)||
			   (*x1==39&&*y1==18)||
			   (*x1==39&&*y1==20))

	
			   *x1=*x1-2;
		}

		break;
	case 80:
		*y1=*y1+1;
		if(*y1>y_b) *y1=y_b;
		else
		{
		
			if((*x1==3&&*y1==2)||
			   (*x1==3&&*y1==4)||
			   (*x1==3&&*y1==6)||
			   (*x1==3&&*y1==8)||
			   (*x1==3&&*y1==10)||
			   (*x1==3&&*y1==12)||
			   (*x1==3&&*y1==14)||
			   (*x1==3&&*y1==16)||
			   (*x1==3&&*y1==18)||
			   (*x1==3&&*y1==20)||

			   (*x1==9&&*y1==2)||
			   (*x1==9&&*y1==4)||
			   (*x1==9&&*y1==6)||
			   (*x1==9&&*y1==8)||
			   (*x1==9&&*y1==10)||
			   (*x1==9&&*y1==12)||
			   (*x1==9&&*y1==14)||
			   (*x1==9&&*y1==16)||
			   (*x1==9&&*y1==18)||
			   (*x1==9&&*y1==20)||

			   (*x1==15&&*y1==2)||
			   (*x1==15&&*y1==4)||
			   (*x1==15&&*y1==6)||
			   (*x1==15&&*y1==8)||
			   (*x1==15&&*y1==10)||
			   (*x1==15&&*y1==12)||
			   (*x1==15&&*y1==14)||
			   (*x1==15&&*y1==16)||
			   (*x1==15&&*y1==18)||
			   (*x1==15&&*y1==20)||

			   (*x1==21&&*y1==2)||
			   (*x1==21&&*y1==4)||
			   (*x1==21&&*y1==6)||
			   (*x1==21&&*y1==8)||
			   (*x1==21&&*y1==10)||
			   (*x1==21&&*y1==12)||
			   (*x1==21&&*y1==14)||
			   (*x1==21&&*y1==16)||
			   (*x1==21&&*y1==18)||
			   (*x1==21&&*y1==20)||

			   (*x1==27&&*y1==2)||
			   (*x1==27&&*y1==4)||
			   (*x1==27&&*y1==6)||
			   (*x1==27&&*y1==8)||
			   (*x1==27&&*y1==10)||
			   (*x1==27&&*y1==12)||
			   (*x1==27&&*y1==14)||
			   (*x1==27&&*y1==16)||
			   (*x1==27&&*y1==18)||
			   (*x1==27&&*y1==20)||

			   (*x1==33&&*y1==2)||
			   (*x1==33&&*y1==4)||
			   (*x1==33&&*y1==6)||
			   (*x1==33&&*y1==8)||
			   (*x1==33&&*y1==10)||
			   (*x1==33&&*y1==12)||
			   (*x1==33&&*y1==14)||
			   (*x1==33&&*y1==16)||
			   (*x1==33&&*y1==18)||
			   (*x1==33&&*y1==20)||

			   (*x1==39&&*y1==2)||
			   (*x1==39&&*y1==4)||
			   (*x1==39&&*y1==6)||
			   (*x1==39&&*y1==8)||
			   (*x1==39&&*y1==10)||
			   (*x1==39&&*y1==12)||
			   (*x1==39&&*y1==14)||
			   (*x1==39&&*y1==16)||
			   (*x1==39&&*y1==18)||
			   (*x1==39&&*y1==20))

			   *y1=*y1-1;
		}
		
		
		break;
	default:
		return;
	}
}