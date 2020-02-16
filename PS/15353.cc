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
	string str1, str2, ans;
	cin >> str1 >> str2;
	int a = str1.size(), b = str2.size();
	if (b > a)
	{
		swap(a, b);
		swap(str1, str2);
	}
	int up = 0;
	for (int i = a, j = b; i > 0 || j > 0; i--, j--)
	{
		int p;
		if (j > 0)
		{
			p = (str1[i - 1] - '0') + (str2[j - 1] - '0')+up;
			if (p > 9)
			{
				up = 1;
				p -= 10;
				ans += to_string(p);
			}
			else
			{
				up = 0;
				ans += to_string(p);
			}
		}
		else
		{
			p = (str1[i - 1] - '0') + up;
			if (p > 9)
			{
				up = 1;
				p -= 10;
				ans += to_string(p);
			}
			else
			{
				up = 0;
				ans += to_string(p);
			}
		}

	}
	if (up)
		ans += to_string(up);
	reverse(ans.begin(), ans.end());
	cout << ans;
}