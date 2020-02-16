#include <stdio.h>
#include <math.h>

int n;
int main()
{
	int TT;
	scanf("%d", &TT);
	while (TT--)
	{
		int N;
		scanf("%d", &N);
		int a = -1;
		int b = -1;
		for (int u = 2; u*u <= 2 * N; u++)
			if (2 * N%u == 0)
			{
				int v = 2 * N / u;
				if ((u + v) % 2 == 1)
				{
					a = (u + v - 1) / 2;
					b = (v - u - 1) / 2;
					break;
				}
			}
		if (a == -1)
			printf("IMPOSSIBLE\n");
		else
		{
			printf("%d = ", N);
			for (int i = b + 1; i<a; i++)
				printf("%d + ", i);
			printf("%d\n", a);
		}
	}
}