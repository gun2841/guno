#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace::std;
int main(void)
{
	int m;
	vector<int> vec;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int c;
		scanf("%d", &c);
		vec.push_back(c);
	}
	int n;
	vector<int> vec2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int c;
		scanf("%d", &c);
		vec2.push_back(c);
	}

	sort(vec.begin(), vec.end());
	
	for (int i = 0; i < n; i++)
	{
		if (binary_search(vec.begin(), vec.end(), vec2[i]))
		{
			printf("1\n");
		}
		else
			printf("0\n");;
	}

	return 0;
}