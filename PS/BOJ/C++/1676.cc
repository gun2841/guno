#include <iostream>
using namespace::std;

int main()
{
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		while (temp % 5 == 0)
		{
			cnt++;
			temp /= 5;
		}
	}
	printf("%d", cnt);
}