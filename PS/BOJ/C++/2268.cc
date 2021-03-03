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
ll init(vector<ll>& arr, vector<ll>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;

	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}
void update(vector<ll>& tree, int node, int start, int end, int idx, ll diff)
{
	if (!(start <= idx && idx <= end))
		return;
	tree[node] += diff;
	if (start != end)
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, idx, diff);
		update(tree, node * 2 + 1, mid + 1, end, idx, diff);
	}
}
ll sum(vector<ll>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<ll> vt(n);
	vector<ll> tree(tree_size);

	init(vt, tree, 1, 0, n - 1);;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 0)
		{
			int c;
			scanf("%d", &c);
			if (b > c)
			{
				swap(b, c);
			}
			printf("%lld\n",sum(tree, 1, 0, n - 1, b - 1, c-1));
		}
		else
		{
			ll c;
			scanf("%lld", &c);
			long long temp;
			temp = c - vt[b-1];
			vt[b-1] = c;
			update(tree, 1, 0, n - 1, b - 1, temp);
		}
	}
}
