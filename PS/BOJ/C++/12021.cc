#include <iostream>
using namespace std;
int main() {
	float x, y;
	cin >> x >> y;
	while (1)
	{
		float x1, y1;
		x1 = (x + y) / 2;
		y1 = 2 * x / (x + y)*y;
		if (x == x1 && y1 == y)
			break;
		x = x1; y = y1;
	}
	printf("%.3lf %.3lf", x, y);
}
