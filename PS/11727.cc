#include <iostream>
using namespace::std;
int dp[1001];
int main()
{
	dp[0] = 1;
	dp[1] = 3;
	int n;
	scanf("%d", &n);
	if (n > 2) {
		for (int i = 2; i < n; i++)
		{
			dp[i] = (dp[i - 1] + 2*dp[i - 2])%10007;
		}
		printf("%d", dp[n - 1]);
	}
	else
		printf("%d", dp[n - 1]);
}