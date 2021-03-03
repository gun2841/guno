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

int main()
{
	int e, s, m;
	cin >> e >> s >> m;
	int ans = 1;
	int fe = 1,fs = 1, fm = 1;
	while (1)
	{
		if (fe == e && fs == s && fm == m)
			break;
		fe++; fs++; fm++; ans++;
		if (fe > 15)
			fe = 1;
		if (fs > 28)
			fs = 1;
		if (fm > 19)
			fm = 1;
	}
	cout << ans;
}