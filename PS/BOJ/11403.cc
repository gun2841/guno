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
int arr[101][101];
int n;
void bfs(int s)
{
	bool check[101] = { false, };
	queue<int> q;
	q.push(s);

	while (!q.empty())
	{
		int x = q.front(); q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (arr[x][i] == 1 && check[i] == false)
			{
				check[i] = true;
				q.push(i);
				arr[s][i] = true;
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= n; i++)
		bfs(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

}
