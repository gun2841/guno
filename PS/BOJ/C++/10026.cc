#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define ull unsigned long long
char arr[102][102];
char arr2[102][102];
int cnt_1 = 0, cnt_2 = 0,n;
int i, j;
int  dfs(int X, int Y, char s) {
	if (X<0 || Y<0 || X>n || Y>n)
		return 0;

	if (arr[X][Y] != s)
		return 0;
	arr[X][Y] = 'A';

	dfs(X + 1, Y,s);
	dfs(X - 1, Y,s);
	dfs(X, Y + 1,s);
	dfs(X, Y - 1,s);
	return 1;
}
int  dfs2(int X, int Y, char s)
{
	if (X<0 || Y<0 || X>n || Y>n)
		return 0;

	if (arr2[X][Y] != s)
		return 0;
	arr2[X][Y] = 'A';

	dfs2(X + 1, Y, s);
	dfs2(X - 1, Y, s);
	dfs2(X, Y + 1, s);
	dfs2(X, Y - 1, s);
	return 1;
}
int main(int argc, char** argv)
{
	cin >> n;
	for (i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = str[j];
			if (arr[i][j] == 'B')
			{
				arr2[i][j] = 'B';
			}
			else
				arr2[i][j] = 'R';
		}

	}

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] == 'R') {
				dfs(i, j, 'R');
				cnt_1++;
			}
			else if (arr[i][j] == 'B')
			{
				dfs(i, j, 'B');
				cnt_1++;
			}
			else if (arr[i][j] == 'G')
			{
				dfs(i, j, 'G');
				cnt_1++;
			}

			if (arr2[i][j] == 'R')
			{
				dfs2(i, j, 'R');
				cnt_2++;
			}
			else if (arr2[i][j] == 'B')
			{
				dfs2(i, j, 'B'); cnt_2++;
			}
			
		}
	//print_();
	cout << cnt_1 << " ";
	cout << cnt_2;
}