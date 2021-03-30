#include <iostream>
#include <bitset>
#include <string>
using namespace::std;

int main()
{
	bitset<100000> b1, b2;
	cin >> b1;
	cin >> b2;
	cout << (b1&b2) << endl;
	cout << (b1|b2) << endl;
	cout << (b1^b2) << endl;
	cout << b1.flip() << endl;
	cout << b2.flip() << endl;
}