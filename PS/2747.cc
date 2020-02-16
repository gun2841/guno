#include <iostream>
using namespace::std;

int main()
{
	int n,temp, f0 = 0, f1 = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	if (n == 0)
		printf("0");
	else
	printf("%d", f1);
}