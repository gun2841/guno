#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <cstring>
using namespace::std;

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	vector<int> vt1(n + 1);
	vector<int> vt2(n + 1);
	vector<int> vt3(n + 1);
	vt1[0] = vt2[0] = vt3[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int d; scanf("%d", &d);
		vt1[i + 1] = vt1[i];
		vt2[i + 1] = vt2[i];
		vt3[i + 1] = vt3[i];
		if (d == 1)
			vt1[i + 1] = vt1[i] + 1;
		else if (d == 2)
			vt2[i + 1] = vt2[i] + 1;
		else
			vt3[i + 1] = vt3[i] + 1;
	}
	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d %d %d\n", vt1[b] - vt1[a - 1], vt2[b] - vt2[a - 1], vt3[b] - vt3[a - 1]);
	}
}
