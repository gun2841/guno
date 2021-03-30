#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace::std;
void recall(int hms) {
	int h = hms / 3600;
	int m = (hms - h * 3600) / 60;
	int s = hms - h * 3600 - m * 60;
	printf("%d %d %d\n", h,m,s);
}
int main()
{
	int h, m, s;
	int total;
	int tc, t, c;
	scanf("%d %d %d", &h, &m, &s);
	total = h * 3600 + m * 60 + s;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%d", &c);
			c %= 86400;
			total += c;
			if (total >= 86400)
				total -= 86400;
		}
		else if (t == 2)
		{
			scanf("%d", &c);
			c %= 86400;
			total -= c;
			if (total < 0)
				total += 86400;
		}
		else {
			recall(total);
		}
	}
}