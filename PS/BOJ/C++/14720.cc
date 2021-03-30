
#include <iostream>
#include <algorithm>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N, first = 0, cnt = 0;
	cin >> N;
	while (N--)
	{
		int a;
		cin >> a;
		if (first == 0 && a == 0)
		{
			first = 1;
			cnt++;
		}
		else if (first == 1 && a == 1)
		{
			first = 2;
			cnt++;
		}
		else if (first == 2 && a == 2) {
			first = 0;
			cnt++;
		}
	}
	cout << cnt;
}