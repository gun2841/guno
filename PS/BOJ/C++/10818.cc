#include <iostream>
using namespace::std;
int main()
{
	int N, max=-1000000, min = 1000000;
	scanf("%d", &N);
	while (N--)
	{
		int a;
		scanf("%d", &a);
		if (a > max)
			max = a;
		if (a < min)
			min = a;
	}
	printf("%d %d", min, max);
}

