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
using namespace::std;
bool c[10]; int a[10];
vector<int> vt;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x; vt.push_back(x);
	}
	if (prev_permutation(vt.begin(), vt.end()))
	{
		for (int i = 0; i < n; i ++ )
			cout << vt[i] << " ";
	}
	else
	{
		cout << "-1";
	}
}