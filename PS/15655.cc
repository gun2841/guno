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
bool c[10]; int a[10];
vector<int> vt;
void solve(int index, int s, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++) 
		{
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = s; i <= n; i++) {
		if (c[i]) continue;
		c[i] = true; 
		a[index] = vt[i-1];
		solve(index + 1, i,n, m);
		c[i] = false;
	}
}
int main()
{
	int n, m;
	cin >> n>> m;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x; vt.push_back(x);
	}
	sort(vt.begin(), vt.end());
	solve(0,1, n, m);
}