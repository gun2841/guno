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
		double f; string str;
		cin >> f; getline(cin, str);
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == ' ')
				continue;
			else
			{
				switch (str[j])
				{
				case '@':
					f *= 3;
					break;
				case '%':
					f += 5;
					break;
				case '#':
					f -= 7;
					break;
				default:
					break;
				}
			}
		}
		printf("%.2f\n", f);
	}
}