#include <iostream>
#include <sstream>
#include <string>
using namespace::std;

int main()
{
	int a = 5;
	int n;
	scanf("%d", &n);
	if (n > 1)
		for (int i = 1; i < n; i++)
		{
			a = (a+ (i - 1) * 3 + 7)%45678;
		}

	cout << a;
}
