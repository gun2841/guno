#include <iostream>
using namespace::std;

int main()
{
	int a = 0, b = 1,c;
	int T;
	scanf("%d", &T);
	c = a + b;
	for (int i = 1; i < T; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	if (T == 0)
		printf("0");
	else
	printf("%d", c);
}