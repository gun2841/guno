#include <iostream>
#include <math.h>

int main(void)
{
	int T, x1, y1, r1, x2, y2, r2;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2)
				printf("-1");
			else
				printf("0");
		}
		else
		{
			int min = abs(r1 - r2);
			double d = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
			if (d< r1 + r2 && d > min) printf("2");
			else if (d == r1 + r2 || d == min) printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
}
