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
#include <stack>
using namespace::std;
#define ll long long
char arr[13][7];
char lazy[12][6];
int find(char c, int x,int y)
{
	
	if (x < 0 || x>11 || y < 0 || y>5)
		return 0;
	if (c != lazy[x][y] || lazy[x][y] == '.')
		return 0;
	int re = 1;
	lazy[x][y] = '.';
	re += find(c, x + 1, y);
	re += find(c, x, y + 1);
	re += find(c, x - 1, y);
	re += find(c, x, y - 1);

	return re;
}
void lazy_update()
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
		{
			lazy[i][j] = arr[i][j];
		}
}
void arr_update()
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
		{
			arr[i][j] = lazy[i][j];
		}
}
void arr_push()
{
	for (int j = 0; j < 6; j++) {
		stack<char> st;
		for (int i = 0; i < 12; i++)
		{
			if (lazy[i][j] != '.')
				st.push(lazy[i][j]);
		}
		int i = 11;
		while (!st.empty())
		{
			arr[i][j] = st.top();
			st.pop();
			i--;
		}
		for (i; i >= 0; i--)
			arr[i][j] = '.';
	}
}
void print()
{
	cout << endl;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}
int main()
{
	int ans = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++)
		{
			cin >> arr[i][j];
		}
	}

	lazy_update();
	bool check = true;
	while (1) {
		check = true;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (arr[i][j] != '.')
				{
					int t = find(arr[i][j], i, j);
					if (t < 4) {
						lazy_update();

						continue;
					}
					else
					{
						arr_update();
					//	print();
						check = false;
					}
				}
			}
		}

		if (check)
			break;
		else
		{
			arr_push();
			lazy_update();
			ans++;
		}
	}
	cout << ans;
}