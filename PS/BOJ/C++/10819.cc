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
vector<int> vt;
int n;
int sum()
{
	int tp = 0;
	for (int i = 0; i < n-1; i++)
	{
		tp += abs(vt[i] - vt[i + 1]);
	}
	return tp;
}
int main()
{
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		vt.push_back(x);
	}
	sort(vt.begin(), vt.end());
	ans = sum();
	while (next_permutation(vt.begin(), vt.end()))
	{
		int max = sum();
		if (max > ans)
			ans = max;
	}
	cout << ans;
}