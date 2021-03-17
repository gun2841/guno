#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n--)
	{
		int tc;
		cin >> tc;
		multiset<int> qu;
		multiset<int>::iterator iter;
		while (tc--)
		{
			char cmd;
			int num;
			cin >> cmd >> num;
			if (cmd == 'I') qu.insert(num);
			else {
				if (qu.empty()) continue;
				if (num == 1) qu.erase(--qu.end());
				else qu.erase(qu.begin());
			}
		}
		if (qu.empty()) cout << "EMPTY\n";
		else { cout << *(--qu.end()) << " " << *(qu.begin()) << "\n"; }
	}
}
