
#include <iostream>
using namespace::std;
int arr[500][500];
int dp[500][500];
bool check[500][500] = { false };
int sum(int i, int j)
{
	int left = check[i+1][j] ? dp[i+1][j] : sum(i+1,j);
	int right = check[i + 1][j+1] ? dp[i + 1][j+1] : sum(i + 1, j+1);
	check[i][j] = true;
	return dp[i][j] = (left >right ? left:right)+arr[i][j];
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 0; i < n; i++)
	{
		dp[n - 1][i] = arr[n - 1][i];
		check[n - 1][i] = true;
	}
	printf("%d", sum(0, 0));
}