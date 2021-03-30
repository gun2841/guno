#include <iostream>
using namespace::std;
int main(void)
{
	int x, y, a=0;
	cin >> x >> y;
	int b[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 1; i<x; i++) {
		a = a + b[i-1];
	}
	a += y;
	a %= 7;
	if (a == 1)
		printf("MON");
	else if (a == 2)
		printf("TUE");
	else if (a == 3)
		printf("WED");
	else if (a == 4)
		printf("THU");
	else if (a == 5)
		printf("FRI");
	else if (a == 6)
		printf("SAT");
	else if (a == 0)
		printf("SUN");
}