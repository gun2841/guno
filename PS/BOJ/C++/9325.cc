#include <iostream>
using namespace::std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int s, n;
		scanf("%d", &s);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int q, p;
			scanf("%d %d", &q, &p);
			s += (q*p);
		}
		printf("%d\n", s);
	}
}