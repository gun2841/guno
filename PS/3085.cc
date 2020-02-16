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
int solve(vector<string> vt)
{
	int n = vt.size();
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = 1; j < n; j++)
		{
			if (vt[i][j] == vt[i][j - 1])
				cnt++;
			else
				cnt = 1;
			if (ans < cnt) ans = cnt;
		}
		cnt = 1;
		for (int j = 1; j < n; j++)
		{
			if (vt[j][i] == vt[j - 1][i])
				cnt++;
			else
				cnt = 1;
			if (ans < cnt) ans = cnt;
		}
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	vector<string> vt;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		vt.push_back(str);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (j + 1 < n) 
			{
				swap(vt[i][j], vt[i][j + 1]);
				int temp = solve(vt);
				if (ans < temp) ans = temp;
				swap(vt[i][j], vt[i][j + 1]);
			}
			if (i + 1 < n)
			{
				swap(vt[i][j], vt[i + 1][j]);
				int temp = solve(vt);
				if (ans < temp) ans = temp;
				swap(vt[i][j], vt[i + 1][j]);
			}
		}
	cout << ans;
}