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
using namespace::std;
bool arr[2000001] = { false, };
int dis[2000001];
int n, k;
int main()
{
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	arr[n] = true;
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		if ((x - 1) >= 0 && arr[x - 1] == false)
		{
			q.push(x - 1);
			arr[x - 1] = true;
			dis[x - 1] = dis[x] + 1;
		}
		if ((x + 1) < 2000001 && arr[x + 1] == false)
		{
			q.push(x + 1);
			arr[x + 1] = true;
			dis[x + 1] = dis[x] + 1;
		}
		if (x * 2 < 2000001 && arr[x * 2] == false)
		{
			q.push(x * 2);
			arr[x * 2] = true;
			dis[x * 2] = dis[x] + 1;
		}
	}
	cout << dis[k];
}
