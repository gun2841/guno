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
	ios_base::sync_with_stdio(false);
	priority_queue<int, vector<int>, greater<int>> plus_q;
	priority_queue<int,vector<int>,less<int>> minus_q;
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (minus_q.size() == 0 && plus_q.size() == 0)
			{
				cout << "0";
			}
			else
			{
				int m = 0, p = 0;
				if (minus_q.empty())
				{
					cout << plus_q.top();
					plus_q.pop();
				}
				else if (plus_q.empty())
				{
					cout << minus_q.top();
					minus_q.pop();
				}
				else
				{
					m = abs(minus_q.top());
					p = plus_q.top();
					if (m <= p)
					{
						cout << minus_q.top();
						minus_q.pop();
					}
					else
					{
						cout << plus_q.top();
						plus_q.pop();
					}
				}
			}
			cout << "\n";
		}
		else
		{
			if (x < 0)
				minus_q.push(x);
			else if (x > 0)
				plus_q.push(x);
		}

	}
}
