#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace::std;
int main()
{
	int n,ans=0;
	vector<int> vt;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a; vt.push_back(a);
	}
	int tp;
	tp = vt[n - 1];
	ans++;
	for (int i = n -2; i >= 0; i--)
	{
		if (tp < vt[i])
		{
			ans++;
			tp = vt[i];
		}
	}
	cout << ans;
}