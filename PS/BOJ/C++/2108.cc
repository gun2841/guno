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
#include <bitset>
using namespace::std;
int arr[8001];
int main() {
	ios_base::sync_with_stdio(false);

	int n,sum =0; cin >> n;
	vector<int> vt(n);
	int mx = -4001;
	int mn = 4001;
	for (int i = 0; i < n; i++)
	{
		cin >> vt[i];
		mx = max(mx, vt[i]);
		mn = min(mn, vt[i]);
		arr[4000 + vt[i]]++;
		sum += vt[i];
	}
	sort(vt.begin(), vt.end());
	cout << round((double)sum / (double)n) << endl;
	int ans = 0;
	int cnt = 0;
	int pr = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (arr[i] != 0)
		{
			if (pr < arr[i])
			{
				pr = arr[i];
				ans = i;
				cnt = 1;
			}
			else if (pr == arr[i])
			{
				cnt++;
				if (cnt == 2)
				{
					ans = i;
				}
			}
		}
	}

	cout << vt[(n-1) / 2] << endl;
	cout << ans - 4000 << endl;
	cout << vt[n - 1] - vt[0];
}