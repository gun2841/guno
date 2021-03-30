#include <iostream>
using namespace::std;

int main()
{
	int T;
	int n;

	scanf("%d", &T);
	while (T--)
	{
		int count = 0;
		scanf("%d", &n);

		while (n != 0)
		{
			if (n % 2 == 1)
				printf("%d ",count);
			n /= 2;
			count++;
		}
		printf("\n");
	}
}