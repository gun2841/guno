#include <iostream>
#include <string>
using namespace::std;
int main()
{
	string str;
	cin >> str;
	float base = int(4 - ( str[0] - 'A'));
	if (str[0] == 'F') {
		cout << fixed;
		cout.precision(1);
		cout << 0.0;
	}
	else {
		if (str[1] == '+') base += 0.3;
		else if (str[1] == '-') base -= 0.3;
		cout << fixed;
		cout.precision(1);
		cout << base;
	}
}


