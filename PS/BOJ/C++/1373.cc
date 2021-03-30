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

int main() {
	ios_base::sync_with_stdio(false);
	string s, ans = "";
	cin >> s;
	int d = s.size() % 3;
	int i = 0;
	if (s[i] == '0') {
		cout << 0;
		return 0;
	}
	if (d != 0) {
		int temp = 0;
		if (d == 1)
		{
			temp = 1;
			i = 1;
		}
		if (d == 2)
		{
			temp = (s[i] - '0') * 2 + (s[i + 1] - '0');
			i = 2;
		}
		ans += (temp + '0');
	}
	for (i; i < s.size(); i+=3)
	{
		int temp = 0;
		temp = (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
		ans += (temp+'0');
	}
	cout << ans;
}