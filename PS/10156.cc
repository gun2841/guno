#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	int K, N, M;
	cin >> K >> N >> M;
	int ans = K * N - M;
	if (ans < 0)
		cout << "0";
	else
		cout << ans;
}