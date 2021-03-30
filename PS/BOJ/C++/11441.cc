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
#include <cstdio>
#include <cstring>
using namespace::std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> psum(n + 1);
	psum[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		psum[i + 1] = psum[i] + a[i];
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << psum[y] - psum[x-1] << "\n";
	}
}