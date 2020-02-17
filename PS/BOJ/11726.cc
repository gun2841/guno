#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <vector>
using namespace::std;
int main()
{
	int a = 1, b = 2;
	int n;
	scanf("%d", &n);
	if (n > 2) {
		for (int i = 2; i < n; i++)
		{
			int c = (a + b) % 10007;
			a = b;
			b = c;
		}
		printf("%d", b);
	}
	else if (n == 1)
		printf("1");
	else
		printf("2");
}