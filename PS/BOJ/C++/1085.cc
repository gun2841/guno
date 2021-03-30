#include <iostream>

using namespace::std;

int main()
{
	int x, y, w, h;
	int a, b, c, d;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	a = h - y;
	b = w - x;
	c = y;
	d = x;

	if (a <= 0 || b <= 0)
		printf("0");
	else
	{
		if (a < b && a < c&& a < d)
			cout << a;
		else if (b < c&& b < d)
			cout << b;
		else if (c < d)
			cout << c;
		else
			cout << d;
	}
}