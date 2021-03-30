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
int arr[129][129];
int n;
int ans[2] = { 0,0 };

bool possible(int i, int j, int d, int t)
{
	if (i + d > n || j + d > n)
		return false;

	for (int a = 0; a < d; a++)
		for (int b = 0; b < d; b++)
		{
			if (arr[a + i][b + j] != t)
				return false;
		}
	return true;
}
void answer(int i, int j, int d, int t)
{
	for (int a = 0; a < d; a++)
		for (int b = 0; b < d; b++)
		{
			arr[a + i][b + j] = 2;
		}
	ans[t]++;
}
void solve(int i, int j)
{
	int temp = n;
	bool check = true;
	while (1)
	{
		if (possible(i, j, temp, arr[i][j]))
		{
			answer(i, j, temp, arr[i][j]);
			return;
		}
		temp /= 2;
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	int t = n;
	while(t){
		for (int i = 0; i < n; i+=t) {
			for (int j = 0; j < n; j+=t) {
				if (arr[i][j] != 2)
					solve(i, j);
			}
		}
		t /= 2;
	}


	cout << ans[0] << endl;
	cout << ans[1];
}
