#include <iostream>
#include <string>
using namespace::std;
int main()
{
	int happy = 0, unhappy = 0;
	string str;
	getline(cin, str);
	int len = str.size();
	for (int i = 0; i < len-2; i++)
	{
		if (str[i] == ':')
		{
			if(str[i+1] == '-')
				if (str[i + 2] == ')')
				{
					happy++;
					i += 2;
				}
		}
		if (str[i] == ':')
		{
			if (str[i + 1] == '-')
				if (str[i + 2] == '(')
				{
					unhappy++;
					i += 2;
				}
		}
	}
	if (happy > unhappy)
		cout << "happy";
	else if (happy  < unhappy)
		cout << "sad";
	else if (happy == 0 && unhappy == 0)
		cout << "none";
	else
		cout << "unsure";
}