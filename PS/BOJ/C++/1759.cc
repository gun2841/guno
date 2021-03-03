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
using namespace::std;
string ans;
bool check(string password)
{
	int ja = 0, mo = 0;
	for (char x : password) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
			mo += 1;
		else
			ja += 1;
	}
	return ja >= 2 && mo >= 1;
}
void go(int n, vector<char> &alpha , string password, int i)
{
	if (password.length() == n)
	{
		if (check(password))
		{
			cout << password << "\n";
		}
		return;
	}
	if (i >= alpha.size()) return;
	go(n, alpha, password + alpha[i], i + 1);
	go(n, alpha, password, i + 1);
}

int main()
{
	int L, C;
	cin >> L >> C;
	vector<char> str;
	for (int i = 0; i < C; i++)
	{
		char x; cin >> x; str.push_back(x);
	}
	sort(str.begin(), str.end());
	go(L, str, ans, 0);
}