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
#include <cstdio>
#include <cstring>
using namespace::std;

int main()
{
	string str;
	cin >> str;
	int ans = 1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'c')
		{
			if (i == 0)
				ans *= 26;
			else
			{
				if (str[i - 1] == 'c')
					ans *= 25;
				else
					ans *= 26;
			}
		}
		else
		{
			if (i == 0)
				ans *= 10;
			else
			{
				if (str[i - 1] == 'd')
					ans *= 9;
				else
					ans *= 10;
			}
		}
	}
	cout << ans;
}