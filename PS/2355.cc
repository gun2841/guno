#include <iostream>
using namespace::std;

int main()
{
	long long i, j;
	cin >> i >> j;
	if (i > j) // 치환
	{
		long long temp = i;
		i = j;
		j = temp;
	}
	cout << (j*(j + 1) - i*(i - 1)) / 2;
}