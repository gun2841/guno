#include <iostream>
using namespace::std;
int main()
{
	int T, count = 0;
	scanf("%d", &T);
	while (T--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		count += b%a;
	}
	printf("%d", count);
}