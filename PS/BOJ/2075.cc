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
priority_queue<int, vector<int>, greater<int>> pq;
void solve(int n)
{
	if (pq.size() < n)
		return;

	while (pq.size() != n)
	{
		pq.pop();
	}
	
}
int main()
{
	int ans=0;
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			int d; cin >> d;
			pq.push(d);
			solve(n);
		}

	cout << pq.top();
}
