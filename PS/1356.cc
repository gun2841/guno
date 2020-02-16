#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;

	for (int i = 1; i < str.size(); i++)
	{
		int a = 1, b = 1;
		for (int j = 0; j < i; j++) { a *= (str[j] - 48); }
		for (int j = i; j < str.size(); j++) { b *= (str[j] - 48); }
		if (a == b) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}
