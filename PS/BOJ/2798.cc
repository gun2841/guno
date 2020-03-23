#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cstring>
#include <cmath>
using namespace::std;

int main()
{
	int n, m,ans=0;
	cin >> n >> m;
	vector<bool> vt;
	vector<int> arr(n);
	for (int i = 0; i < n - 3; i++)
		vt.push_back(false);
	vt.push_back(true);
	vt.push_back(true);
	vt.push_back(true);
	for (int i = 0; i < n ; i++)
		cin >> arr[i];
	do
	{
		int d = 0;
		for (int i = 0; i < n; i++)
			if (vt[i])
				d += arr[i];
		if (d == m)
		{
			cout << d;
			return 0;
		}
		if (d < m)
		{
			ans = max(ans, d);
		}
	} while (next_permutation(vt.begin(), vt.end()));
	cout << ans;
}