#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <utility>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
using namespace::std;

int getParent(int set[], int x)
{
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}
void unionParent(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a < b) set[b] = a;
	else set[a] = b;
}
int find(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return 1;
	else return 0;
}
class edge {
public:
	int node[2];
	int dis;
	edge(int a, int b, int D)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->dis = D;
	}
	bool operator<(edge &ed) {
		return this->dis < ed.dis;
	}
};
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	vector<edge> vt;
	int m = costs.size();
	for (int i = 0; i < m; i++)
	{
		vt.push_back(edge(costs[i][0], costs[i][1], costs[i][2]));
	}
	sort(vt.begin(), vt.end());
	int set[n];
	for (int i = 0; i < n; i++)
	{
		set[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		if (!find(set, vt[i].node[0] , vt[i].node[1] ))
		{
			sum += vt[i].dis;
			unionParent(set, vt[i].node[0] , vt[i].node[1] );
		}
	}

	return sum;
}