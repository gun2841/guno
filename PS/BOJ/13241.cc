#include <iostream>
#include <string>
using namespace::std;

long long int gcd(long long int a, long long int b)
{
	while(b != 0)
	{
		long long int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	long long int a, b;
	cin >> a >> b;
	cout << a / gcd(a, b) *b;
}
