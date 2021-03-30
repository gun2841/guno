#include <iostream>
#include<vector>
#include <algorithm>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int N, K, cnt = 0;
	cin >> N >> K;
	vector<int> vt(N);
	for (int i = 0; i < N; i++)
		cin >> vt[i];
	sort(vt.begin(), vt.end());
	int ans = 0, d = 0, j = 0;
	for (int i = 0; i < N; i++)
	{
		if (vt[i] - vt[j] > K) j++;
		ans = max(ans, i - j + 1);
	}
	cout << ans;
}