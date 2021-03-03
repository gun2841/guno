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
#include <stack>
using namespace::std;

int main()
{
	int a, b;
	cin >> a >> b;
	int ans = 0;

	vector<int> vt;
	int t = 1;
	int cnt = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (cnt == t)
		{
			t++;
			cnt = 0;
		}
		vt.push_back(t);
		cnt++;
	}
	for (int i = a-1; i < b; i++)
	{
		ans += vt[i];
	}
	cout << ans;
}