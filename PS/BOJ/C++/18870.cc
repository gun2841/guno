#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> vt(n);
	set<int> st;
	map<int, int> mp;
	for (int i = 0;i < n;i++)
	{
		cin >> vt[i];
		st.insert(vt[i]);
	}
	set<int>::iterator iter; int id = 0;
	for (iter = st.begin();iter != st.end();iter++)
	{
		mp[*iter] = id++;
	}
	for (int i = 0;i < n;i++)
	{
		cout << mp[vt[i]] << " ";
	}
}
