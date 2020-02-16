#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int Testcase;
	vector<int> vt;
	cin >> Testcase;
	while (Testcase--)
	{
		int N,ans =0;
		cin >> N;
		int a; cin >> a; vt.push_back(a);
		for (int i = 1; i < N; i++)
		{
			int a; cin >> a; vt.push_back(a);
			for (int j = 0; j < i; j++)
			{
				if (a >= vt[j])
					ans++;
			}
		}
		cout << ans <<endl;
		vt.clear();
	}
}