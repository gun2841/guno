#include <iostream>
using namespace::std;
int main()
{
	unsigned long long n, a = 1;
	cin >> n;

		while (n)
		{
			if (n == 0) {
				break;
			}
			a *= n;
			n--;
		}
		cout << a;
	
}
