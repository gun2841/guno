#include <iostream>
using namespace::std;

int main()
{
	int n;
	cin >> n;
	for (int l = 0; l < n; l++) {
		for (int i = 0; i < 2 * n - l - 1; i++)
		{
			if (i < l)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
	for (int l = n - 2; l >= 0; l--	)
	{
		for (int i = 0; i < 2 * n - l - 1; i++)
		{
			if (i < l)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
}
