#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;
int maxAns = -1000000000;
int minAns = 1000000000;
int n;
int number[12] = { 0, };
vector<int> op(4);
void solve(int idx,int value)
{
	if (idx == n)
	{
		minAns = min(value, minAns);
		maxAns = max(value, maxAns);
		return;
	}
	if (op[0] > 0)
	{
		op[0] -= 1;
		solve(idx + 1, value + number[idx]);
		op[0] += 1;
	}
	if (op[1] > 0)
	{
		op[1] -= 1;
		solve(idx + 1, value - number[idx]);	op[1] += 1;
	}
	if (op[2] > 0)
	{
		op[2] -= 1;
		solve(idx + 1, value * number[idx]);
		op[2] += 1;
	}
	if (op[3] > 0)
	{
		op[3] -= 1;
		solve(idx + 1, value / number[idx]);
		op[3] += 1;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> number[i];
	for (int i = 0;i < 4;i++)
	{
		cin >> op[i];
	}
	solve(1, number[0]);
	cout << maxAns << endl;
	cout << minAns;
}