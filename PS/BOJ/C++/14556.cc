#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	//std::ios_base::sync_with_stdio(false);
	long long n;
	cin >> n;
	long long ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans = (ans + 2 * (i - 1) * ans)% 1000000009;
	}
	cout << ans;
}