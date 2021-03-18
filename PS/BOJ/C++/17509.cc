#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int ans = 0;
	vector<pair<int, int>> vt;
	for (int i = 0;i < 11;i++)
	{
		int a, b;
		cin >> a >> b;
		vt.push_back(make_pair(a, b));
	}
	sort(vt.begin(), vt.end());
	int t = 0, temp = 0;
	for (int i = 0; i < 11;i++)
	{
		t += vt[i].first;
		ans += (t + 20 * vt[i].second);
	}
	cout << ans;
}
