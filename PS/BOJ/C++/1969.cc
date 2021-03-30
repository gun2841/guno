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
struct alpha {
	char c;
	int cnt;
};
bool cmp(alpha a, alpha b)
{
	if (a.cnt == b.cnt)
		return a.c < b.c;
	else
		return a.cnt > b.cnt;
}
int main()
{
	int n, m;
	vector<string> vt;
	string ans;
	int ans_cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		vt.push_back(str);
	}
	for (int i = 0; i < m; i++)
	{
		alpha arr[4] = { {'A', 0} , {'C',0 } , {'G',0}, {'T',0} };
		for (int j = 0; j < n; j++)
		{
			if (vt[j][i] == 'A')
				arr[0].cnt++;
			else if (vt[j][i] == 'C')
				arr[1].cnt++;
			else if (vt[j][i] == 'G')
				arr[2].cnt++;
			else if (vt[j][i] == 'T')
				arr[3].cnt++;
		}
		sort(arr, arr+4, cmp);
		ans += arr[0].c;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vt[i][j] != ans[j])
				ans_cnt++;
		}
	}
	cout << ans<<"\n";
	cout << ans_cnt;
}	