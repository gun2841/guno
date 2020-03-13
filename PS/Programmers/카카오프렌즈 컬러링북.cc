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
int mm,nn;
int arr[102][102] = { 0 };
int df(int i, int j, int ma)
{
	int ans = 1;
	arr[i][j] = 0;
	if (arr[i + 1][j] == ma)
		ans += df(i + 1, j, ma);
	if (arr[i - 1][j] == ma)
		ans += df(i - 1, j, ma);
	if (arr[i][j + 1] == ma)
		ans += df(i, j + 1, ma);
	if (arr[i][j - 1] == ma)
		ans += df(i, j - 1, ma);
	return ans;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	mm = m;
	nn = n;

	int number_of_area = 0;
	int max_size_of_one_area = 0;
	for(int i = 0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			arr[i+1][j+1] = picture[i][j];
		}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] != 0) {
				number_of_area++;
				max_size_of_one_area = max(max_size_of_one_area, df(i, j, arr[i][j]));
			}
		}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}