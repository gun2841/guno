#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

int main()
{
	vector<int> vt;
	int ans = 0;
	for (int i = 0; i < 7; i++)
	{
		int n;
		cin >> n;
		if (n % 2 == 1) {
			ans += n;
			vt.push_back(n);
		}
	}
	sort(vt.begin(), vt.end());
	if (vt.empty())
	{
		cout << "-1";
		return 0;
	}
	cout << ans<< endl;
	cout << vt[0];
}