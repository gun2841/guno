#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace::std;
int gcd(int a, int b)
{
	int tmp, n;
	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while (b != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}
int main()
{
	int n, s ,ans;
	cin >> n >> s;
	vector<int> vt(n);
	ans = s;
	for (int i = 0; i < n; i++)
	{
		cin >> vt[i];
		vt[i] = abs(s - vt[i]);
		if (i == 0)
			ans = vt[i];
		else
			ans = gcd(ans, vt[i]);
	}
	cout << ans;
}