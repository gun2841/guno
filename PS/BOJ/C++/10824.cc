#include <iostream>
#include <string>
using namespace::std;
int main()
{
	string a, b, c, d;
	long long i, j;
	cin >> a >> b >> c >> d;
	a += b;
	c += d;
	i = stoll(a);
	j = stoll(c);
	printf("%lld", i + j);
}