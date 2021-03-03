#include <iostream>
#include <string>
using namespace::std;

int main()
{
	string str;
	while (1)
	{
		int count = 0;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++)
		{
			if(str[i] != ' ')
				count += (str[i] - 64)*(i + 1);
		}
		if (str[0] == '#')
			break;
		cout << count << endl;
	}
}