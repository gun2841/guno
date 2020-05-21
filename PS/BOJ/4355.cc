#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
#include <stack>
using namespace::std;
#define ll long long


int main()
{
	ios_base::sync_with_stdio(false);
	do {

		ll n;
		cin >> n;
		if (n == 0)
			break;
		ll ans = n;
		ll prime = 2;

		while (prime * prime <= n)
		{
			if (n % prime == 0)
				ans = ans / prime * (prime - 1);
			while (n % prime == 0)
				n = n / prime;
			prime++;
		}
		if (n != 1)
			ans = ans / n * (n - 1);
		cout << ans<<"\n";
	} while (1);

}