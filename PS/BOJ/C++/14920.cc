#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace::std;
#define ull unsigned long long
int main()
{
	ios_base::sync_with_stdio(false);
	int n,i;
	cin >> n;
	for (i = 0;; i++)
	{
		if (n == 1)
			break;
		if (n % 2 == 0)
			n /= 2;
		else
			n = n * 3 + 1;
	}
	cout << i+1;
}