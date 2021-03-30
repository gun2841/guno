#include <iostream>
using namespace::std;
int main()
{
	int a[3], N, han;
	cin >> N;
	if (N < 100) han = N;
	else if (N >= 100 && N <= 1000)
	{
		han = 99;
		for (int i = 100; i <= N; i++)
		{
			int t = i;
			for (int j = 0; j < 3; j++)
			{
				a[j] = t % 10;
					t /= 10;
			}
			if ((a[0] - a[1]) == (a[1] - a[2])) han++;
		}
	}
	if (N == 1000)
		han--;
	printf("%d", han);
}