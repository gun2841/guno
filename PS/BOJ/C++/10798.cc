#include <iostream>
#include <string>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	string str[5];
	int size = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> str[i];
		if (size < str[i].length())
			size = str[i].length();
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i >= str[j].size())
				continue;

			cout << str[j][i];
		}
	}
}