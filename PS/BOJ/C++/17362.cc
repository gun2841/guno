#include <iostream>

using namespace::std;

int main()
{
	int n;
	cin >> n;
	int t = (n - 1) / 8;
	t = t * 8 + 1;
	if ((n - 1) % 8 == 0)
		cout << "1";
	else if ((n - 3) % 4 == 0)
		cout << "3";
	else if ((n - 5) % 8 == 0)
		cout << "5";


	else if (((t + 1) == n) || ((t + 7) == n))
		cout << "2";
	else
		cout << "4";
}