#include <iostream>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T, n;
	cin >> T;
	while (T--)
	{
		int low = 100;
		int sum = 0;
		for (int i = 0; i < 7; i++)
		{
			cin >> n;
			if (n % 2 == 0)
			{
				if (low > n)
					low = n;
				sum += n;
			}
		}
		cout << sum << " " << low << endl;
	}
}
