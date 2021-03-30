#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>> vt;
	vector<int> ans;
	priority_queue<int, vector<int>, greater<int>> qu;
	for (int i = 0;i < n;i++)
	{
		int a, b;
		cin >> a >> b;
		vt.push_back(make_pair(a, b));
	}
	sort(vt.begin(), vt.end());
	qu.push(vt[0].second);
	for (int i = 1;i < vt.size();i++)
	{
		if (qu.top() <= vt[i].first)
		{
			qu.pop(); qu.push(vt[i].second);
		}
		else
		{
			qu.push(vt[i].second);
		}
	}

	cout << qu.size();
}
