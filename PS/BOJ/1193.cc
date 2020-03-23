#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cstring>
using namespace::std;

int main()
{
	int x;
	cin >> x;
	int n = 1;
	int d;
	do
	{
		d = n * (n + 1) / 2;
		n++;
	} while (d < x);
	//cout << d << endl;
	n -= 1;
	if (n % 2 == 1)
	{
		int t = d - x;
		cout << 1 + t << "/" << n - d + x<< endl;
	}
	else
	{
		int t = d - x;
		cout << n - d + x << "/" << 1 + t;
	}
}