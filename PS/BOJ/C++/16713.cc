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
	//ios_base::sync_with_stdio(false);
	long long n, m, ans = 0;
	scanf("%lld %lld", &n, &m);
	getchar();
	vector<long long> vt(n + 1, 0);
	vector<long long> mp;
	for (int i = 0; i < n; i++)
	{
		long long d; scanf("%lld",&d);
		getchar();
		vt[i + 1] = vt[i] ^ d;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		getchar();
		long long d = vt[b]^vt[a-1];
		mp.push_back(d);
	}

	for (auto& v : mp)
	{
		ans ^= v;
	}
	cout << ans;
}
