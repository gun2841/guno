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
#include <stack>
using namespace::std;
struct book
{
	string name;
	int cnt=0;
};
bool cmp(book a, book b)
{
	if (a.cnt > b.cnt)
		return true;
	else if (a.cnt == b.cnt)
		if (a.name < b.name)
			return true;

	return false;
}
int main()
{
	int n;
	cin >> n;
	vector<book> vt;
	map<string,book> mp;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (mp.find(s) != mp.end())
		{
			mp[s].cnt++;
		}
		else
		{
			book bk;
			bk.name = s; bk.cnt = 1;
			mp.insert(make_pair(s, bk));
		}
	}
	
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		vt.push_back(it->second);
	}
	sort(vt.begin(), vt.end(), cmp);

	cout << vt[0].name;
}