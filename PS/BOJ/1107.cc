#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <stack>
using namespace::std;
bool broken[10];
int solve(int c)
{
	if (c == 0)
	{
		return broken[0] ? 0 : 1;
	}
	int len = 0;
	while (c > 0)
	{
		if (broken[c % 10]) return 0;
		len += 1;
		c /= 10;
	}
	return len;
}
int main()
{
	int c;
	cin >> c;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x; broken[x] = true;
	}
	int ans = c - 100;
	if (ans < 0)
		ans = -ans;
	for (int i = 0; i <= 1000000; i++)
	{
		int n = i;
		int len = solve(n);
		if (len > 0) {
			int press = n - c;
			if (press < 0)
				press = -press;
			if (ans > len + press)
				ans = len + press;
		}
	}
	cout << ans;
}