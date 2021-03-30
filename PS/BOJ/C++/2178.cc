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
int arr[101][101];
bool check[101][101];
int dist[101][101];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = true;
	dist[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (check[nx][ny] == false && arr[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
					check[nx][ny] = true;
				}
			}
		}
	}
	cout << dist[n - 1][m - 1];
}
