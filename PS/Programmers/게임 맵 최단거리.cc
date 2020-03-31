#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace::std;
bool check[101][101];
int dist[101][101] = { -1 ,};
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int solution(vector<vector<int> > maps)
{
	int answer = 0;
	int n = maps.size();
	int m = maps[0].size();

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = true;
	dist[0][0]=1;
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				if (check[nx][ny] == false && maps[nx][ny] == 1)
				{
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
					check[nx][ny] = true;
				}
			}
		}
	}
	if (dist[n - 1][m - 1] == 0)
		return -1;
	return dist[n-1][m-1];
}