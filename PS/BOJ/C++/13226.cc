#include <iostream>
#include <math.h>
using namespace::std;
int solve(int L, int U)
{
	int ans = 0;
	for (int k = L; k <= U; k++) {
		int cnt = 0;
		for (int i = 1; i*i <= k; i++)
		{
			if (i*i == k)
				cnt++;
			else if (k%i == 0)
				cnt += 2;
		}
		if (cnt > ans)
			ans = cnt;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int C;
	cin >> C;
	while (C--)
	{
		int L, U;
		cin >> L >> U;
		cout << solve(L, U) << endl;
	}
}