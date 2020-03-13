#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <utility>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
using namespace::std;
int psum[1001][1001];
int n, m;
bool check(int l)
{
	for (int i = 0; i <= n - l; i++)
		for (int j = 0; j <= m - l; j++)
			if (psum[i + l][j + l] - psum[i + l][j] - psum[i][j + l] + psum[i][j] == l * l)return true;
	return false;
}
int solution(vector<vector<int>> board)
{
	int answer = 1234;
	n = board.size();
	m = board[0].size();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			psum[i][j] = board[i-1][j-1] + psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1];

	int left = 0;
	int right = 1000;
	while (left != right)
	{
		int mid = (left + right) / 2 + 1;
		if (check(mid)) left = mid;
		else right = mid - 1;
	}
	return left*left;
}