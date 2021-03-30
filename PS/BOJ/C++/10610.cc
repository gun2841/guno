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
#include <cstdio>
#include <cstring>
using namespace::std;

bool cmp(char a, char b)
{
	return b < a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str,ans ="";
	int sum = 0;
	bool check = false;
	cin >> str;
	sort(str.begin(), str.end(),cmp);
	for (int i = 0; i < str.size(); i++)
	{
		ans += str[i];
		sum += str[i] - '0';
	}
	if (sum % 3 == 0 && str[str.size() - 1] == '0')
		cout << ans;
	else
		cout << "-1";
}