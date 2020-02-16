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
#define ull unsigned long long 
int arr[100001];
ull solve(int start, int end)
{
	if (start == end) return (ull)arr[start] * arr[end];
	int mid = (start + end) / 2;
	ull left = solve(start, mid);
	ull right = solve(mid + 1, end);

	ull maxValue = max(left, right);

	int l = mid;
	int r = mid + 1;

	ull sum = arr[l] + arr[r];
	ull minValue = min(arr[l], arr[r]);

	maxValue = max(maxValue, sum * minValue);
	while (l > start || r < end)
	{
		if (r < end && (l == start || arr[l - 1] < arr[r + 1]))
		{
			sum += arr[++r];
			minValue = min(minValue, (ull)arr[r]);
		}
		else
		{
			sum += arr[--l];
			minValue = min(minValue, (ull)arr[l]);
		}
		ull crossSum = sum * minValue;
		maxValue = max(maxValue, crossSum);
	}
	return maxValue;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	cout << solve(1, n);
}	