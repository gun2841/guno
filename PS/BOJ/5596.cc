#include <iostream>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T=0, S=0;
	for (int i = 0; i < 4; i++)
	{
		int a;
		cin >> a; T += a;
	}
	for (int i = 0; i < 4; i++)
	{
		int a;
		cin >> a; S += a;
	}
	if (T > S)
		cout << T;
	else cout << S;
}
