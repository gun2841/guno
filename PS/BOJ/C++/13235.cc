#include <iostream>
#include <string>
#include <algorithm>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	string str, com_str;
	cin >> str;
	com_str = str;
	reverse(com_str.begin(), com_str.end());
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != com_str[i])
		{
			cout << "false";
			return 0;
		}
	}
	cout << "true";
}