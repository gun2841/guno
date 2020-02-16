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
int arr[10][10];
int n;
int solve()
{
	int ans = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (arr[vt[i]][vt[i + 1]] == 0)
			return 999999999;
		ans += arr[vt[i]][vt[i + 1]];
	}
	if (arr[vt[n - 1]][vt[0]] == 0)
		return 999999999;
	ans += arr[vt[n - 1]][vt[0]];

	return ans;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++)
		vt.push_back(i);
	int ans = solve();
	while (next_permutation(vt.begin(), vt.end()))
	{
		int min = solve();
		if (ans >min)
			ans = min;
	}
	cout << ans;
}