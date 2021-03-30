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
#include <set>
using namespace::std;

int main()
{
	set<string> st;
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		st.insert(str);
	}
	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		if (st.count(str))
		{
			ans++;
		}
	}
	cout << ans;
}