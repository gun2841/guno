#include <iostream>
#include <cstdio>
using namespace::std;
#define  min(a,b) ((a)>(b))?(b):(a)

int dp[1001][4];
int temp[1001][4];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3;  j++) {
			scanf("%d", &temp[i][j]);
		}

	dp[1][0] = temp[1][0];
	dp[1][1] = temp[1][1];
	dp[1][2] = temp[1][2];

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = min(dp[i - 1][1] + temp[i][0], dp[i - 1][2] + temp[i][0]);
		dp[i][1] = min(dp[i - 1][0] + temp[i][1], dp[i - 1][2] + temp[i][1]);
		dp[i][2] = min(dp[i - 1][0] + temp[i][2], dp[i - 1][1] + temp[i][2]);
	}

	printf("%d\n", min(min(dp[N][0], dp[N][1]), dp[N][2]));
}