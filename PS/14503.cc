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
int arr[51][51];
int n, m;
struct robot
{
	int x, y; //로봇의 현재 위치
	int dir; // 방향
	int move()
	{
		switch (dir)
		{
		case 0:
			dir = 3;
			if (arr[x][y - 1] == 0 && y > 1) {
				y -= 1;
				return 2; // 2번으로 돌아가라
			}
			return 1; // 1번으로 돌아가라
		case 1:
			dir = 0;
			if (arr[x - 1][y] == 0 && x > 1) {
				x -= 1;
				return 2;
			}
			return 1;
		case 2:
			dir = 1;
			if (arr[x][y + 1] == 0 && y < m - 1)
			{
				y += 1;
				return 2;
			}
			return 1;
		case 3:
			dir = 2;
			if (arr[x + 1][y] == 0 && x < n - 1)
			{
				x += 1;
				return 2;
			}
			return 1;
		}
	}
	int back()
	{
		switch (dir)
		{
		case 0:
			if (arr[x + 1][y] == 1 || x + 1 > n)
				return 3; // 종료
			x += 1;
			return 2; //2번
		case 1:
			if (arr[x][y - 1] == 1 || y == 0)
				return 3;
			y -= 1;
			return 2;
		case 2:
			if (arr[x - 1][y] == 1 || x == 0)
				return 3;
			x -= 1;
			return 2;
		case 3:
			if (arr[x][y + 1] == 1 || y + 1 > m)
				return 3;
			y += 1;
			return 2;

		}
	}
};
int main()
{
	robot rt;
	int ans = 0;
	cin >> n >> m;
	cin >> rt.x >> rt.y >> rt.dir;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	while (1)
	{
		bool go = false;
		if(arr[rt.x][rt.y] == 0)
		arr[rt.x][rt.y] = 2; // 현재 위치 청소
		for (int i = 0; i < 4; i++)
		{
			
			if (rt.move() == 2) {
				go = true;
				break;
			}
		}
		if (!go)
		{
			if (rt.back() == 3) {
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
		//	cout << arr[i][j] << " ";
			if (arr[i][j] == 2)
				ans++;
		}
		//cout << endl;
	}
	cout << ans;
}