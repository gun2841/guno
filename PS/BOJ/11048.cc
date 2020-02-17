#include <iostream>

using namespace::std;

int arr[1001][1001] = { 0 };
int dp[1001][1001];
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	//입력부분
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = (max(dp[i][j-1], dp[i-1][j]) + arr[i][j]);
		}
	cout << dp[N][M];



}