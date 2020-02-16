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
#include <bitset>
using namespace::std;
int n, m;
int arr[1001][1001];
int d[1001][1001];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int main()
{
	queue<pair<int, int>> q;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			d[i][j] = -1;
			if (arr[i][j] == 1)
			{
				q.push(make_pair(i, j));
				d[i][j] = 0;
			}
		}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (d[nx][ny] == -1 && arr[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = d[x][y] + 1;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (ans < d[i][j])
				ans = d[i][j];
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 0 && d[i][j] == -1)
				ans = -1;
	// 체크하는거
	cout << ans;
}
