#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define ull unsigned long long
int arr[27][27];
int solve(int i, int j)
{
	int ans =1;
	arr[i][j] = 0;

	if (arr[i + 1][j] == 1)
		ans += solve(i + 1, j);

	if (arr[i-1][j] == 1)
		ans += solve(i -1, j);
	if (arr[i][j+1] == 1)
		ans += solve(i , j+1);
	if (arr[i][j-1] == 1)
		ans += solve(i, j-1);

	return ans;
}
int main(int argc, char** argv)
{
	vector<int> vt;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d", &arr[i][j]);
		}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == 1)
				vt.push_back(solve(i, j));
		}
	int n = vt.size();
	cout << n << endl;
	sort(vt.begin(), vt.end());
	for (int i = 0; i < n; i++)
	{
		cout << vt[i] << endl;
	}
}