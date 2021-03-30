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
long long arr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	int  n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	long long  min = 1000000000;
	long long ans = 0;
	for (int i = 1; i < n - 1; i++)
	{
		long long tmp = abs(arr[0] - 2 * arr[i] + arr[i + 1]);
		ans = max(ans, tmp);

		tmp = abs(arr[i - 1] - 2 * arr[i] + arr[n - 1]);
		ans = max(ans, tmp);
	}
	cout << ans;
}