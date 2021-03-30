#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <numeric>
#include <queue>
using namespace::std;

int  m;
int arr[201][201];
bool check[201] = { false };
bool dfs(int x)
{
	if (check[x] == true)
		return false;
	check[x] = true;
	for (int i = 0; i < m; i++)
	{
		if (arr[x][i] == 1 && check[i] == false)
		{
			arr[x][i] = 0;
			arr[i][x] = 0;
			dfs(i);
		}
	}
	return true;
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	m = n;
	for (int i = 0; i < 200; i++)
		check[i] = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = computers[i][j];

	for(int i =0;i<n;i++)
			if (dfs(i))
				answer++;

	
	return answer;
}