#include <iostream>
using namespace::std;

int main()
{
	unsigned long long n, v;
	cin >> n;
	v = n;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	unsigned long long u=0;
	while (n)
	{
		u += (n % 10);
		n /= 10;
	}

	while (v%u != 0)
	{
		v += 1;
		u = 0;
		n = v;
		while (n)
		{
			u += (n % 10);
			n /= 10;
		}
	}
	cout << v;
}
