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
using namespace::std;
int main() {
	ios_base::sync_with_stdio(false);
	string s;
	string ans = "";
	getline(cin, s);
	bool check = false;
	string temp = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ' && !check)
		{
			reverse(temp.begin(), temp.end());
			ans += temp;
			ans += " ";
			temp = "";
			continue;
		}
		else if (s[i] == '>')
		{
			temp += '>';
			ans += temp;
			temp = "";
			check = false;
			continue;
		}
		else if (s[i] == '<')
		{
			check = true;
			reverse(temp.begin(), temp.end());
			ans += temp;
			temp = "";
		}
		temp += s[i];
	}
	reverse(temp.begin(), temp.end());
	ans += temp;

	cout << ans;
}