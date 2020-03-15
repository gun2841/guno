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
	int ans=0;
	ios_base::sync_with_stdio(false);
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int d; cin >> d;
		pq.push(d);
	}
	if (n == 1) {
		cout << "0";
		return 0;
	}
	while (1)
	{
		if (pq.size() == 1)
			break;
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();
		pq.push(x + y);
		ans =ans+x + y;
	}
	cout << ans;
}
