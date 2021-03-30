#include <iostream>
using namespace::std;

int main()
{
	int A, B, C, D, P;
	cin >> A >> B >> C >> D >> P;
	A *= P;
	
	if (P>=C)
	{
		B = B + D*(P-C);
	}
	else
		B = B;

	if (A > B)
		cout << B;
	else
		cout << A;
}