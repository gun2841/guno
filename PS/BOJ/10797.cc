#include <iostream>
using namespace::std;
int main()
{
	int n,cnt=0;
	scanf("%d", &n);
	int c = 5;
	while (c--)
	{
		int a;
		scanf("%d", &a);
		if (a == n)
			cnt++;
	}
	printf("%d", cnt);
}

