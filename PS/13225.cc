#include <iostream>
#include <math.h>
using namespace::std;
int solve(int n)
{
	int ans = 0;
	for (int i = 1; i*i <= n; i++)
	{
		if (i*i == n)
			ans++;
		else if (n%i == 0)
			ans+=2;
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
		int N;
		cin >> N;
		cout << N << " " <<solve(N) << endl;
	}
}