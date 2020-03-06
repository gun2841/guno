#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace::std;

int gcd(int a, int b)
{
	return (a % b == 0 ? b : gcd(b, a % b));
}
int main()
{
	int a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;
	int x = gcd(b, d);
	 a = a * (d / x) + c * (b / x);
	 b = b * d / x;
	 c = gcd(a, b);
	cout << a / c << " " << b / c;
}