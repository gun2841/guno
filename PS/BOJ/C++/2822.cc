#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
using namespace std;
#define ull unsigned long long

int main(int argc, char** argv)
{
	vector<pair<int, int>> vt;
	vector<int> vt2;
	for (int i = 1; i < 9; i++)
	{
		int n;
		cin >> n;
		vt.push_back(make_pair(n, i));
	}
	sort(vt.begin(), vt.end());
	int ans = 0;
	for (int i = 7; i > 2; i--)
	{
		ans += vt[i].first;
		vt2.push_back(vt[i].second);
	}
	sort(vt2.begin(), vt2.end());
	cout << ans <<endl;
	for (int i = 0; i < 5; i++)
	{
		cout << vt2[i] << " ";
	}
}