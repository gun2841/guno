#include <iostream>
#include <cmath>
using namespace::std;

int main()
{
	int n, m;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int cnt = 0;
		cin >> n >> m;
		for(int a = 1; a < n;a++)
			for (int b = a + 1; b < n; b++)
			{
				if (((a*a) + (b*b) + m) % (a*b) == 0)
					cnt++;
			}
		cout << cnt << "\n";
	}
}