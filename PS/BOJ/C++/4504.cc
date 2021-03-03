#include <iostream>
using namespace::std;

int main()
{
	int n;
	int mult=1;
	scanf("%d", &n);
	scanf("%d", &mult);
	while(mult != 0)
	{
		if (mult % n == 0)
			printf("%d is a multiple of %d.\n", mult, n);
		else
			printf("%d is NOT a multiple of %d.\n", mult, n);
		scanf("%d", &mult);
	}
}
