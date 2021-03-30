#include <iostream>
#include <string>
using namespace::std;
int main()
{
	string str;
	cin >> str;
	int count = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] < 'D')
			count += 3;
		else if (str[i] < 'G')
			count += 4;
		else if (str[i] < 'J')
			count += 5;
		else if (str[i] < 'M')
			count += 6;
		else if (str[i] < 'P')
			count += 7;
		else if (str[i] < 'T')
			count += 8;
		else if (str[i] < 'W')
			count += 9;
		else
			count += 10;
	}
	cout << count;
}