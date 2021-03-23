#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace::std;
#define ll long long
ll arr[100001];
ll solve(int s, int e)
{
	if (s == e) return 0;
	if (s + 1 == e) return arr[s];
	ll m = (s + e) / 2;
	ll ans = max(solve(s, m), solve(m, e));

	ll w = 1, h = arr[m], l = m, r = m;
	while (r - l + 1 < e - s)
	{
		ll p = l > s ? min(h,arr[l - 1]) : -1;
		ll q = r < e - 1 ? min(h, arr[r + 1]) : -1;
		if (p >= q) {
			h = p;
			l--;
		}
		else {
			h = q;
			r++;
		}
		ans = max(ans, ++w*h);
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	do {
		int n;
		cin >> n;
		if (n == 0) return 0;
		for (int i = 0;i < n;i++)
		{
			arr[i] = 0;
		}
		for (int i = 0;i < n;i++)
		{
			cin >> arr[i];
		}
		cout << solve(0, n) << "\n";
	} while (1);
}
