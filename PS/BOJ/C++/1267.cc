#include <iostream>

using namespace::std;

int main()
{
	int m=0, y =0;
	int N, cost;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &cost);
		m = m + (cost / 60) + 1;
		y = y + (cost / 30) + 1;
	}
	m *= 15; y *= 10;
	if (m > y)
		printf("Y %d", y);
	else if (m < y)
		printf("M %d", m);
	else 
		printf("Y M %d", y);
}
