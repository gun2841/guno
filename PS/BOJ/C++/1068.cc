#include <iostream>
#include <vector>
using namespace::std;
vector<int> tree[51];
int root, T;//삭제노드
int dfs(int v)
{
	int s = 0;
	if (v == T) return 0;
	else if (tree[v].empty() || tree[v][0] == T && tree[v].size() == 1) return 1;
	else for (int a : tree[v]) s += dfs(a);
	return s;
}
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == -1)
			root = i;
		else tree[a].emplace_back(i);
	}
	scanf("%d", &T);
	printf("%d", dfs(root));
}