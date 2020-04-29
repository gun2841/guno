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
#define mod 1000000007;
ll init(vector<ll>& arr, vector<ll>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	else {
		int mid = (start + end) / 2;
		return tree[node] = ((init(arr, tree, node * 2, start, mid)% 1000000007) * (init(arr, tree, node * 2 + 1, mid + 1, end)% 1000000007))%mod;
	}
}
ll update(vector<ll>& tree, int node, int start, int end, int idx, int b)
{
	if (!(start <= idx && idx <= end))
		return tree[node];
	if (start == end)
		return tree[node] = b;
	int mid = (start + end) / 2;
	return tree[node] = (
		update(tree, node * 2, start, mid, idx, b) *
		update(tree, node * 2 + 1, mid + 1, end, idx, b))% 1000000007;
	
}
ll mul(vector<ll>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return (mul(tree, node * 2, start, mid, left, right) * mul(tree, node * 2+1, mid + 1, end, left, right))% 1000000007;
}
int main()
{
	int n, m,k;
	scanf("%d %d %d", &n, &m,&k);

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));

	vector<ll> vt(n);
	vector<ll> tree(tree_size);

	for (int i = 0; i < n; i++)
		scanf("%lld", &vt[i]);
	init(vt, tree, 1, 0, n - 1);
	m += k;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 2)
		{
			int c;
			scanf("%d", &c);
			if (b > c)
			{
				swap(b, c);
			}
			printf("%lld\n", mul(tree, 1, 0, n - 1, b - 1, c - 1));
		}
		else
		{
			ll c;
			scanf("%lld", &c);
		
			update(tree, 1, 0, n - 1, b - 1,c);
		}
	}
}
