#include <iostream>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	int a, b, n, w;
	cin >> a >> b >> n >> w;
	int ans = 0, ans_n = 0;
	for (int i = n-1; i >0; i--)
	{
		if (b*i + a * (n - i) == w) {
			ans++;
			ans_n = i;
		}
	}
	if (ans == 0 || ans > 1)
		cout << "-1";
	else
	cout << n - ans_n << " " << ans_n;
}