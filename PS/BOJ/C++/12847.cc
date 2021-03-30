#include <iostream>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	long long salary[100010];
	int n, m;
	long long  ans = 0;

	cin >> n >> m;
	for (int i = 1; i < n+1; i++)
	{
		cin >> salary[i];
		salary[i] = salary[i - 1] + salary[i];
	}
	for (int i = m; i < n + 1; i++)
	{
		long long temp = salary[i] - salary[i - m];
		if (temp > ans)
			ans = temp;
	}

		cout << ans;
}