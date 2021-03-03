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

ll initmax(vector<ll>& arr, vector<ll>& tree, int node, int start, int end)
{
	if(start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = max(initmax(arr, tree, node * 2, start, mid), initmax(arr, tree, node * 2 + 1, mid + 1, end));
}
ll initmin(vector<ll>& arr, vector<ll>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = min(initmin(arr, tree, node * 2, start, mid), initmin(arr, tree, node * 2 + 1, mid + 1, end));
}
ll min_search(vector<ll>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 1000000000;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return min(min_search(tree, node * 2, start, mid, left, right), min_search(tree, node * 2 + 1, mid + 1, end, left, right));
}
ll max_search(vector<ll>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return -1;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return max(max_search(tree, node * 2, start, mid, left, right), max_search(tree, node * 2 + 1, mid + 1, end, left, right));
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));

	vector<ll> vt(n);
	vector<ll> max_tree(tree_size);
	vector<ll> min_tree(tree_size);

	for (int i = 0; i < n; i++)
		scanf("%lld", &vt[i]);
	initmax(vt, max_tree, 1, 0, n - 1);
	initmin(vt, min_tree, 1, 0, n - 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld %lld\n", min_search(min_tree, 1, 0, n - 1, a - 1, b - 1),max_search(max_tree,1,0,n-1,a-1,b-1));
	}
}
