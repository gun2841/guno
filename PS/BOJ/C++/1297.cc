#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	float temp = (float)a / sqrt((b*b) + (c*c));
	b = (float)b *temp;
	c = (float)c * temp;
	cout << b <<" " <<c;
}
