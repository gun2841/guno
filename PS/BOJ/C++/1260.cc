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
int n, m, v;
bool check[1001] = { false , };
bool b_check[1001] = { false, };
queue<int> q;
vector<vector<int>> vt(1001);
void dfs(int x);
void bfs(int x);
int main()
{
	cin >> n >> m >> v;
	//vector<vector<int>> vt(n+1);
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(vt[i].begin(), vt[i].end());
	}
	dfs(v);
	cout << endl;
	bfs(v);
}
void dfs(int x)
{
	check[x] = true;
	cout << x << " ";
	for (int i = 0; i < vt[x].size(); i++)
	{
		int y = vt[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}

}
void bfs(int x)
{
	b_check[x] = true; q.push(x);
	while (!q.empty())
	{
		int y = q.front(); 
		cout << y << " ";
		q.pop();
		for (int i = 0; i < vt[y].size(); i++)
		{
			int z = vt[y][i];
			if (b_check[z] == false) {
				b_check[z] = true;
				q.push(z);
			}
		}
	}
}