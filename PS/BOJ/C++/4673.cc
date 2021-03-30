#include <stdio.h>

int main()
{
	int i, n, a[10035];
	for (i = 1; i < 10001; i++)
	{
		a[i] = 1;
	}
	for (i = 1; i < 10001; i++)
	{
		n = i;
		if (a[n] == 0)
			continue;
		else
		{
			while (n <= 10000)
			{
				if (i != n)
					a[n] = 0;
				n = n + n / 1000 + (n % 1000) / 100 + (n % 100) / 10 + n % 10;
			}
		}
	}
	for (i = 1; i < 10001; i++)
		if (a[i] != 0)
			printf("%d\n", i);

	return 0;
}