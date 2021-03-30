#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
int V, E, K;
int visit[20001];
int gajungchi[20001];
struct node {
	int num;
	int gjc;
};
struct cmp {
	bool operator()(node a, node b) {
		return (a.gjc > b.gjc);
	}
};
priority_queue <node, vector<node>, cmp> pq;
vector <node> vec[20001];
void dijkstra() {
	pq.push({ K,gajungchi[K] });
	while (!pq.empty())
	{
		node t = pq.top(); pq.pop();
		if (!visit[t.num]) {
			visit[t.num] = 1;
			for (int a = 0; a < vec[t.num].size(); a++) {
				int tn = vec[t.num][a].num, tg = vec[t.num][a].gjc;
				if (gajungchi[tn] > tg + gajungchi[t.num]) {
					gajungchi[tn] = tg + gajungchi[t.num];
					pq.push({ tn,gajungchi[tn] });
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E >> K;
	int u, v, w;
	for (int i = 1; i <= E; i++) {
		cin >> u >> v >> w;
		vec[u].push_back({ v,w });
	}
	for (int i = 1; i <= V; i++)gajungchi[i] = INF;
	gajungchi[K] = 0;
	dijkstra();

	for (int i = 1; i <= V; i++)
		if (gajungchi[i] != INF)
			cout << gajungchi[i] << "\n";
		else
			cout << "INF\n";
	return 0;
}