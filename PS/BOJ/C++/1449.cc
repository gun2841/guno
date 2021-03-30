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
int main()
{
	int N, L;
	vector<int> vt;
	cin >> N >> L;
	L -= 1;
	for (int i = 0; i < N; i++)
	{
		int a; cin >> a; vt.push_back(a);
	}
	sort(vt.begin(), vt.end());
	int ans = 1;
	int start = vt[0] + L;
	for (int i = 1; i < N;i++)
	{
		if (vt[i] > start)
		{
			ans++;
			start = vt[i] + L;
		}

	}
	cout << ans;
}	