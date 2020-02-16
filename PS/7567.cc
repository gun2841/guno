#include <iostream>
#include <string>
using namespace::std;
int main()
{
	string str;
	int mode=0, height = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' && mode == 0){
			height += 10;
			mode = 1;
		}
		else if (str[i] == ')' && mode == 0)
		{
			height += 10;
			mode = 2;
		}
		else if (str[i] == '(' && mode == 1)
		{
			height += 5;
			mode = 1;
		}
		else if (str[i] == ')' && mode == 1)
		{
			height += 10;
			mode = 2;
		}
		else if (str[i] == '(' && mode == 2)
		{
			height += 10;
			mode = 1;
		}
		else if (str[i] == ')' && mode == 2)
		{
			height += 5;
			mode = 2;
		}
	}
	printf("%d", height);
}

