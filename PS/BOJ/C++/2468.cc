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
#include <cstdio>
#include <cstring>
using namespace::std;
int arr[102][102];
int r[102][102];
bool visit[101][101] = { false, };
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int ans = 0, cnt = 0;
int n;

void bfs(int x, int y)
{
	queue < pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		r[x][y] = cnt;

		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dir[k][0];
			int ny = y + dir[k][1];
			if (1 <= nx && nx <= n && 1 <= ny && ny <= n)
			{
				if (visit[nx][ny] == false  && r[nx][ny] == 0)
				{
					q.push(make_pair(nx, ny));
					visit[nx][ny] = true;
				}
			}
		}
	}
}
int main()
{
	int rain = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			cin >> arr[i][j];
	while (1) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (arr[i][j] <= rain)
					r[i][j] = -1;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (r[i][j] == 0)
				{
					cnt++;
					bfs(i, j);
				}
		if (cnt == 0)
			break;
		if (cnt > ans)
			ans = cnt;
		cnt = 0; rain++; 
		memset(visit, false, sizeof(visit));
		memset(r, 0, sizeof(r));
	}
	if (ans == 0)
		cout << "1";
	else
		cout << ans;
}