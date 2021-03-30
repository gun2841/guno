#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int x;
	vector<int> vt;
	cin >> x;
	for (int i = 0; i < n - 1; i++) {
		int t; cin >> t;
		vt.push_back(t);
	}
	int cnt = 0;
	bool check = true;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	while (check)
	{
		sort(vt.begin(), vt.end());
		check = true;
		for (int i = vt.size()-1; i >= 0; i--)
		{
			if (vt[i] >= x)
			{
				vt[i]--;
				x++;
				cnt++;
				break;
			}
			else
			{
				check = false;
			}
		}
	}
	cout << cnt;
}