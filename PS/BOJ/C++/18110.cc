#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <cstring>
#include <set>
#include <cmath>
using namespace::std;

int main()
{
	int n;
	cin >> n;
	vector<int> vt(n);
	for (int i = 0; i < n; i++)
		cin >> vt[i];

	sort(vt.begin(), vt.end());

	int piv = (int)round(n * 0.15f);


	int ans = 0;
	int cnt = 0;
	for (int i =piv; i < n-piv; i++)
	{
		ans += vt[i];
		cnt++;
	}

	//cout << ans << " " << cnt << endl;
	if (ans == 0)
		cout << "0";
	else
		cout << round((float)ans/cnt);
}