#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace::std;
int main()
{
	vector<int> vt, ans;
	int n, q;
	scanf("%d %d", &n, &q);
	vt.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int v; scanf("%d", &v);
		vt.push_back(v);
	}
	sort(vt.begin(), vt.end());
	for (int i = 1; i <= n; i++)
	{
		vt[i] = vt[i] + vt[i - 1];
	}
	for (int i = 0; i < q; i++)
	{
		int L, R;
		scanf("%d %d", &L, &R);
		ans.push_back(vt[R] - vt[L - 1]);
	}
	for (int i = 0; i < q; i++)
	{
		printf("%d\n", ans[i]);
	}
}