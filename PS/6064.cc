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
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int j = 0;
		x -= 1; y -= 1;
		bool check = false;
		for(int k =x;k<n*m;k+=m)
			if (k % n == y) {
				cout << k + 1 << endl;
				check = true;
				break;
			}
		if (!check)
			cout << -1 << endl;
	}
}