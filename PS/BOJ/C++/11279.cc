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
	//ios_base::sync_with_stdio(false);
	priority_queue<int> q;
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		scanf("%d", &x);
		if (x != 0)
		{
			q.push(x);
		}
		else
		{
			if (q.size() != 0)
			{
				printf("%d", q.top());
				q.pop();
			}
			else
				printf("0");
			printf("\n");
		}
		
	}
}
