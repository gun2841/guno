#include <iostream>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T,a=0;
	for (int i = 0; i < 5; i++)
	{
		cin >> T;
		a += T;
	}
	cout << a;
}
