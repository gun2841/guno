#include <iostream>
#include <vector>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, k, ans = 1;;
	cin >> n >> k;
	for (int i = n; i > n - k; i--)
	{
		ans *= i;
	}
	for (int i =2; i <= k; i++)
		ans /= i;
	cout << ans;
}