#include <iostream>
using namespace::std;
void empty()
{
	printf(" ");
}
void stard()
{
	printf("*");
}
int main()
{
	int star;
	scanf("%d", &star);
	for (int i = 0; i < star; i++)
	{
		for (int j = 0; j < star - i-1; j++)
			empty();
		for (int j = 0; j < i*2+1; j++)
			stard();
		printf("\n");
	}
	
}