#include <iostream>
#include <stack>
#include <string>
using namespace::std;
long long gcd(long long a, long long b);
int main()
{
	int n;
	cin >> n;
	long long a, b;
	while (n--)
	{
		cin >> a >> b;
		long long g = gcd(a, b);
		cout << a * b / g<< endl;
	}
}
long long gcd(long long a, long long b)
{
	return (a%b == 0 ? b : gcd(b, a%b));
}