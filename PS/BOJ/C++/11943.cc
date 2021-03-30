#include <iostream>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int a, b, c, d,max = 0;
	cin >> a >> b;
	cin >> c >> d;
	if (a + d > b + c)
		cout << b + c;
	else
		cout << a + d;
}
