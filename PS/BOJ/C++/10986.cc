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
	ios_base::sync_with_stdio(false);
	long long n, m,answer=0;
	cin >> n >> m;
	vector<long long> vt(n + 2,0);
	vector<long long> ans(m + 1,0);
	for (int i = 0; i < n; i++)
	{
		long long d; cin >> d;
		vt[i + 1] = vt[i] + d;
	}

	for (int i = 0; i <= n; i++)
	{
		ans[vt[i] % m]++;
	}
	
	for (int i = 0; i < m; i++)
	{
		if (ans[i] < 2)
		{

		}
		else
		answer += (ans[i] * (ans[i] - 1)) / 2;
	}
	cout << answer;
}
