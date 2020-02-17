#include <iostream>
using namespace::std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int space = n-i-1;space >0;space--)
			printf(" ");
		for (int j = 0; j < 2 * i+1; j++)
		{
			if ((i == 0 || i == n-1 ) || (j == 0 || j == 2 * i))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
