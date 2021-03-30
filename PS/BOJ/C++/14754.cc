#include <iostream>
using namespace::std;
 long long arr[1001][1001];
 long long sum[1001][1001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			sum[i][j] = 0;
		}

	for (int i = 0; i < n; i++) {
		int b_i=i, b_j=0;
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] > arr[b_i][b_j])
			{
				b_i = i; b_j = j;
			}
		}
		sum[b_i][b_j] = arr[b_i][b_j];
	}
	for (int j = 0; j < m; j++) {
		int b_i = 0, b_j = j;
		for (int i = 0; i < n; i++)
		{
			if (arr[i][j] > arr[b_i][b_j])
			{
				b_i = i; b_j = j;
			}
		}
		sum[b_i][b_j] = arr[b_i][b_j];
	}
	long long ans=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (sum[i][j] == 0)
				ans += arr[i][j];
		}
	}
	cout << ans;
}