#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace::std;
unsigned long long arr[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	unsigned long long ans = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++)
		ans += arr[i];

	cout << ans +arr[n-1]*(n-1);
}