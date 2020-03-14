#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <cstring>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> vt(n + 2);
		int ans = -999999999;
		vt[0] = 0;
		for (int i = 0; i < n; i++)
		{
			int d; cin >> d;
			vt[i + 1] = vt[i] + d;
		}
		for(int i =1;i<=n;i++)
			for (int j = i; j <= n; j++)
			{
				ans = max(ans, vt[j] - vt[i-1]);
			}
		cout << ans << "\n";
	}
}
