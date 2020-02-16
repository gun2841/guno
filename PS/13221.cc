#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	int x, y,M_x, M_y;
	cin >> x >> y;
	int min = 9876543;
	int N;
	cin >> N;
	while (N--)
	{
		int a, b;
		cin >> a >> b;
		int d = abs(x - a) + abs(y - b);
		if (min > d) {
			min = d;
			M_x = a; M_y = b;
		}
	}
	cout << M_x << " " << M_y;
}