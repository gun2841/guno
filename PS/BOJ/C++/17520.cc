#include <iostream>
#include <cmath>
using namespace::std;
int main()
{
	unsigned long long n,ans=1;
	cin >> n;
	n = (n + 1) / 2;
	for (unsigned long long a=0; a < n; a++)
	{
		ans *= 2;
		ans %= 16769023;
	}
	cout << ans;
}