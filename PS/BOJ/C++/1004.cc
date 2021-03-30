#include <iostream>
using namespace::std;
int main(void)
{
	int x1, x2, y1, y2, cnt, T,n;
	scanf("%d", &T);
	while (T--)
	{
		cnt = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		while (n--)
		{
			int cx, cy, r;
			long long tmp;
			scanf("%d %d %d", &cx, &cy, &r);
			tmp = (long long)(((x1 - cx)*(x1 - cx) + (y1 - cy)*(y1 - cy) - r*r)*(long long)((x2 - cx)*(x2 - cx) + (y2 - cy)*(y2 - cy) - r*r));
			if (tmp <= 0)
				cnt++;
		}
		printf("%d\n", cnt);
	}
}
