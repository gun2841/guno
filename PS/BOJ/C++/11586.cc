#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace::std;
int n;
vector<string> vt;
vector<string> ans;
void st()
{
	for (int a = 0; a < n; a++) {
		string temp;
		for (int i = n; i > 0; i--)
		{
			temp += vt[a][i - 1];
		}
		ans.push_back(temp);
	}
}
void se()
{
	for (int a = 0; a < n; a++) {
		ans.push_back(vt[n-a-1]);
	}
}
void el()
{
	for (int i = 0; i < n; i++)
		ans.push_back(vt[i]);
}
int main()
{
	string str;
	int ts;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		vt.push_back(str);
	}
	cin >> ts;
	if (ts == 2)
		st();
	else if (ts == 3)
		se();
	else
		el();
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << endl;
	}
}