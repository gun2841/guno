#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace::std;
int main()
{
	string str;
	int t;
	cin >> t;
	cin.ignore();
	for (int i = 0; i < t; i++)
	{
		getline(cin, str);
		stringstream ss(str);
		string a;
		while (ss >> a) {
			reverse(a.begin(), a.end());
			cout << a << " ";
		}
		cout << "\n";
	}
}