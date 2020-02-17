#include <stdio.h>

int main()
{
	int a, b, c, num, n = 1;
	scanf("%d", &num);
	a = num / 10;
	b = num % 10;
	c = a + b;

	while (1) {
		if (num == b * 10 + c)
			break;
		a = b;
		b = c;
		c = (a + b) % 10;
		n++;
	}
	printf("%d\n", n);
	return 0;
}