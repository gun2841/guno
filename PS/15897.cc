#include <iostream>
#include <cmath>
using namespace::std;

int main()
{
	int  n;
	long long cnt = 0;
	cin >> n;
	n--;

	for (int i = n + 1; i != 0; i = n / ((n / i) + 1))
		cnt += (n / i + 1) * (i - (n / ((n / i) + 1)));
	cout << cnt;

}
