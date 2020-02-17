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
bool check[1001] = { false , };
vector<int> vt[1001];
void dfs(int x);
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		vt[u].push_back(v);
		vt[v].push_back(u);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == false) {
		
			dfs(i);
			ans++;
		}
	}
	cout << ans;
}
void dfs(int x)
{
	check[x] = true;
	for (int i = 0; i < vt[x].size(); i++)
	{
		int y = vt[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}

}