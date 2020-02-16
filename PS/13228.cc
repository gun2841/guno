#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	int C;
	cin >> C;
	while (C--)
	{
		int x1, y1, f1, x2, y2, f2;
		cin >> x1 >> y1 >> f1 >> x2 >> y2 >> f2;
		if (x1 == x2 && y1 == y2)
			cout << abs(f1 + f2) << endl;
		else
		{
			cout << f1 + f2 + abs(x1 - x2) + abs(y1 - y2) << endl;
		}
	}
}