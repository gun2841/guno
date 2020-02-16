#include <iostream>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int L, A, B, C, D;
	cin >> L;
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> D;
	if (A%C != 0)
	{
		A = A / C + 1;
	}
	else
		A = A / C;
	if (B%D != 0)
	{
		B = B / D + 1;
	}
	else
		B = B / D;

	if (A > B)
		cout << L - A;
	else
		cout << L - B;
}