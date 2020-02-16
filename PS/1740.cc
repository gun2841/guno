#include <iostream>

using namespace::std;
int main()
{
	unsigned long long N, ans =0, a=1;
	cin >> N;
	for (int i = 0; ; i++)
	{
		if (N % 2 == 0)
		{
			N /= 2;
			a *= 3;
		}
		else
		{
			ans += a;
			N /= 2;
			a *= 3;
		}

		if (N < 1)
			break;
	}
	cout << ans;
	return 0;
}