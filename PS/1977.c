#include <stdio.h>
#include <math.h>
int main()
{
	int i,N, M, sum = 0, min;
	scanf("%d", &N);
	scanf("%d", &M);
	if (N > 1)
		min = (int)sqrt((double)N) + 1;
	else
		min = 1;
	for(i = min; i*i <= M; i++)
	{
		sum += i*i;
	}
	if (sum > 0) {
		printf("%d\n", sum);
		printf("%d\n", min * min);
	}
	else
		printf("-1");
}