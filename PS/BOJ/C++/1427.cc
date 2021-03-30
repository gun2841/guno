#include <iostream>
#include <string>
#include <algorithm>
using namespace::std;
int main()
{
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	for (int i = str.size() - 1; i >= 0; i--)
		cout << str[i];
}

