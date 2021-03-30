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
int n;
vector<string> ans;
bool check[10];
char a[10];
bool good(char x, char y, char op)
{
	if (op == '<')
		if (x > y) return false;
	if (op == '>')
		if (x < y) return false;

	return true;
}
void go(int index, string num)
{
	if (index == n + 1) {
		ans.push_back(num);
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (check[i]) continue;
		if (index == 0 || good(num[index - 1], i + '0', a[index - 1])) {
			check[i] = true;
			go(index + 1, num + to_string(i));
			check[i] = false;
		}
	}
}
int main()
{
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		char x; cin >> a[i];
	}
	go(0, str);
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << endl;
	cout << ans[0];
}