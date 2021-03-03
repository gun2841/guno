#include <iostream>
#include <string>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		str[i] = str[i] - 3;
		if (str[i] < 65)
			str[i] += 26;
	}
	cout << str;
}
