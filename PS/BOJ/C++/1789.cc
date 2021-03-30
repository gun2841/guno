#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	unsigned long long n, a;
	cin >> n;

	a = sqrt((n * 2));
	while (( a*a )+ a  > n*2)
	{
		a--;
	}
	cout << a;
}