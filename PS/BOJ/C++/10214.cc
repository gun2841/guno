#include <iostream>
using namespace::std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b;
		int y = 0, k = 0;
		for (int i = 0; i < 9; i++)
		{
			scanf("%d %d", &a, &b);
			y += a;
			k += b;
		}
		if (y > k)
			printf("Yonsei\n");
		else if (y < k)
			printf("Korea\n");
		else
			printf("Draw\n");
	}
}