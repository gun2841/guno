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
int w, h;
int arr[50][50] = { 0, };
int visit[50][50] = { 0 };
int dir[8][2] = { {1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0} };

void go(int i, int j)
{
	int  nx, ny;

	visit[i][j] = 1;
	for (int x = 0; x < 8; x++)
	{
		nx = i + dir[x][0];
		ny = j + dir[x][1];
		if (nx >= h || nx<0 || ny>=w || ny < 0)
			continue;

		if(visit[nx][ny] == 0 && arr[nx][ny]==1)
			go(nx,ny);
	}
}
int main()
{
	scanf("%d %d", &w, &h);
	do {
		int ans = 0;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++)
			{
				visit[i][j] = 0;
			}

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] == 1 && visit[i][j]==0) {
					go(i, j);
					ans++;
				}
			}

		cout << ans << endl;
	} while (scanf("%d %d", &w, &h));
}
