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
int arr[100001];
#define impossi 100000
#define max_n 101
#define max_k 10001
int N, K, cost[max_n], dp[max_n][max_k];
int solve(int n, int k)
{
	if (n == N) return (k == 0 ? 0 : impossi);
	if (dp[n][k] != -1) return dp[n][k];

	int ans = solve(n + 1, k);
	if (k >= cost[n])ans = min(ans, solve(n, k - cost[n]) + 1);
	dp[n][k] = ans;
	return ans;
}
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> cost[i];
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= K; j++)
			dp[i][j] = -1;

	int ans = solve(0, K);
	if (ans == impossi) cout << "-1";
	else cout << ans;
}	