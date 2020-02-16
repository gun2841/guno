#include <iostream>
#include <vector>
using namespace::std;

int main()
{
	int N, Q;
	vector<int> vt;
	cin >> N >> Q;
	for (int i = 0; i < N; i++)
	{
		int t; cin >> t; vt.push_back(t);
	}
	for (int i = 0; i < Q; i++)
	{
		int a, b, ans = 0; 
		cin >> a >> b;
		for (int j = a; j < b; j++)
		{
			ans += abs(vt[j ] - vt[j-1]);
		}
		cout << ans<<"\n";
	}
}