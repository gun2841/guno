#include <iostream>
using namespace::std;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	while (c--)
	{
		a ^= b;
	}
	cout << a;
}

