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
int arr[16][2];
int n;
int sum=0;
void solve(int start, int ans)
{
	if (start == n +1)
	{
		sum = max(ans, sum);
		return;
	}
	if (start > n) return;

	solve(start + arr[start][0], ans + arr[start][1]);
	solve(start + 1, ans);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}
	solve(1, 0);
	cout << sum;
}