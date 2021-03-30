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
struct work {
	int d;
	int w;
};
bool cmp(work a, work b)
{
	if (a.w == b.w)
		return a.d < b.d;
	else
		return a.w < b.w;
}
int arr[1001];
int main()
{
	int n;
	cin >> n;
	vector<work> vt;
	for (int i = 0; i < n; i++)
	{
		int d, w;
		cin >> d >> w;
		work wk = { d,w };
		vt.push_back(wk);
	}
	sort(vt.begin(), vt.end(),cmp);
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[vt[i].d] == 0) {
			arr[vt[i].d] = vt[i].w;
		}
		else {
			int id = vt[i].d;
			while (id > 0)
			{
				if (arr[id] == 0)
				{
					arr[id] = vt[i].w;
					break;
				}
				id--;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 1001; i++)
	{
		ans += arr[i];
	}
	cout << ans;
}	