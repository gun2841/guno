#include <iostream>
using namespace::std;
int solve(int a, int b, int c)
{
	if (a == b && b == c)
	{
		return 10000 + a * 1000;
	}
	else if (a == b || b == c || a == c)
	{
		if (a == b || a == c)
			return 1000 + a * 100;
		if(b==c)
			return 1000 + b * 100;
	}
	else
	{
		if (a > b) {
			if (a > c)
				return a * 100;
			else if (c > a)
				return c * 100;
		}
		else if (b > a) {
			if (b > c)
				return b * 100;
			else if (c > b)
				return c * 100;
		}
		
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int N,ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int temp = solve(a, b, c);
		if (ans < temp)
		{
			ans = temp;
		}
	}
	cout << ans;
}
