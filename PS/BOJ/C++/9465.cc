#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace::std;
int a[100001] ,b[100001];
int dp[100001][3];
int main()
{
	int Testcase, n;
	scanf("%d", &Testcase);
	while (Testcase--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", b + i);
		}
		dp[0][0] = a[0];
		dp[0][1] = b[0];
		dp[0][2] = 0;

		for (int j = 1; j < n; j++)
		{
			dp[j][0] = max(dp[j - 1][1], dp[j - 1][2]) + a[j];
			dp[j][1] = max(dp[j - 1][0], dp[j - 1][2]) + b[j];
			dp[j][2] = max(dp[j - 1][0], dp[j - 1][1]);
		}

		int ans = max(max(dp[n-1][0], dp[n - 1][1]), dp[n - 1][2]);
		printf("%d\n", ans);
	}
}