#include <iostream>
#include <string>
using namespace::std;
int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		string str;
		cin >> str;
		if (str[str.size() / 2] == str[str.size() / 2 - 1])
			cout << "Do-it" << endl;
		else
			cout << "Do-it-Not" << endl;
	}
	return 0;
}