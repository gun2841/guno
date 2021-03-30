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
	vector<int> vt;
	int sum = 0, a, b;
	for (int i = 0; i < 9; i++)
	{
		int n; cin >> n; vt.push_back(n);
		sum += n;
	}
	sort(vt.begin(), vt.end());
	for(int i =0;i<8;i++)
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - vt[i] - vt[j] == 100)
			{
				for (int a = 0; a < 9; a++)
				{
					if (a == i || a == j)
						continue;
					cout << vt[a] << endl;
				}
				return 0;
			}
		}
}