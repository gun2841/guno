#include <iostream>
#include <string>
using namespace::std;

int main()
{
	string str, ch;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 97 && str[i] <=122)
		{
			if (str[i] >= 110)
				str[i] -= 13;
			else
				str[i] += 13;
		}
		else if (str[i] <= 90 && str[i] >=65)
		{
			if (str[i] >= 78)
				str[i] -= 13;
			else
				str[i] += 13;
		}
	}
	cout << str;
}