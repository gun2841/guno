#include <iostream>
#include <string>
using namespace::std;
int main()
{
	string str, ans;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] < 91 && str[i] != 45)
			ans += str[i];
	}
	cout << ans;
}

