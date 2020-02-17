#include <iostream>
#include <cstdio>
using namespace::std;

int main()
{
	int N;
	scanf("%d", &N);
	int a = 1, b = 2,c=0;
	if (N > 2)
	{
		for (int i = 2; i < N; i++)
		{
			c = (a + b) % 15746;
			a = b % 15746;
			b = c % 15746;
		}
		cout << c%15746;
	}
	else if (N == 2)
		cout << 2;
	else
		cout << 1;
}
