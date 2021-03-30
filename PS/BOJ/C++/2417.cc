#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	unsigned long long  a;
	unsigned long long ans = 0;
	cin >> a;
	for (int i = 0;; i++)
	{
		if (ans*ans >= a)
			break;

		ans++;
	}
	cout << ans;
}