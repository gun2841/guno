#include <stdio.h>
#include <math.h>
int main() {
	int p, a, b, c, d, n,i;
	double max = -1, answer = 0;
	double v;
	scanf("%d %d %d %d %d %d", &p,&a,&b,&c,&d,&n);
	for (i = 1; i <= n; i++)
	{
		v = (double)p * (sin(a*i + b) + cos(c*i + d) + 2);
		if (max > v) {
			if (answer > max - v)
				answer = answer;
			else
				answer = max - v;
		}
		else
			max = v;
	}
	printf("%.9lf\n", answer);
	return 0;
}