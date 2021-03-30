#include <iostream>
using namespace::std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	a += b;
	int ans = 0;
	while (1)
	{
		if (a < c)
			break;
		a -= c;
		ans += 1;
		a += 1;
	}
	cout << ans;
}
