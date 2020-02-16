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
int arr[21][21];
struct dice
{
	int top = 0;
	int bottom = 0;
	int right = 0;
	int left = 0;
	int front = 0;
	int back = 0;
	void east(int x)
	{
		int temp = top;
		top = left;
		left = bottom;
		if (x != 0)
			bottom = x;
		else
			bottom = right;
		right = temp;
	}
	void west(int x)
	{
		int temp = top;
		top = right;
		right = bottom;
		if (x != 0)
			bottom = x;
		else
			bottom = left;
		left = temp;
	}
	void north(int x)
	{
		int temp = top;
		top = front;
		front = bottom;
		if (x != 0)
			bottom = x;
		else
			bottom = back;
		back = temp;
	}
	void south(int x)
	{
		int temp = top;
		top = back;
		back = bottom;
		if (x != 0)
			bottom = x;
		else
			bottom = front;
		front = temp;
	}
};
void print_map(int x,int y)
{
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	struct dice dc;
	for(int i = 0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	for (int i = 0; i < k; i++)
	{
		int a; cin >> a;
		if (a == 1 && y + 1 < m)
		{
			y++;
			dc.east(arr[x][y]);
			if (arr[x][y] == 0)
				arr[x][y] = dc.bottom;
			else
				arr[x][y] = 0;
			cout << dc.top << endl;
		}
		else if (a == 2 && y - 1 >= 0)
		{
			y--;
			dc.west(arr[x][y]);
			if (arr[x][y] == 0)
				arr[x][y] = dc.bottom;
			else
				arr[x][y] = 0;
			cout << dc.top << endl;
		}
		else if (a == 3 && x - 1 >= 0)
		{
			x--;
			dc.north(arr[x][y]);
			if (arr[x][y] == 0)
				arr[x][y] = dc.bottom;
			else
				arr[x][y] = 0;
			cout << dc.top << endl;
		}
		else if (a == 4 && x + 1 < n)
		{
			x++;
			dc.south(arr[x][y]);
			if (arr[x][y] == 0)
				arr[x][y] = dc.bottom;
			else
				arr[x][y] = 0;
			cout << dc.top << endl;
		}
	//	print_map(n, m);
	//	cout << x <<" " <<  y << " " << arr[x][y] << " "<<endl;
	}
	
}