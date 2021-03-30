#include <iostream>
#include <string>
using namespace std;


int main() {
	string str;
	cin >> str;
	int size=0;
	for (int i = 0; i < str.size();)
	{
		if (str[i] == 'c')
		{
			size++;
			i++;
			if (str[i] == '=')
			{
				i++;
			}
			else if (str[i] == '-')
			{
				i++;
			}
		}
		else if (str[i] == 'd')
		{
			size++;
			i++;
			if (str[i] == 'z')
			{
				if (str[i + 1] == '=')
				{
					i++;
					i++;
				}
			}
			else if (str[i] == '-')
			{
				i++;
			}
		}
		else if (str[i] == 'l')
		{
			size++;
			i++;
			if (str[i] == 'j')
			{
				i++;
			}
		}
		else if (str[i] == 'n')
		{
			size++;
			i++;
			if (str[i] == 'j')
			{
				i++;
			}
		}
		else if (str[i] == 's')
		{
			size++;
			i++;
			if (str[i] == '=')
			{
				i++;
			}
		}
		else if (str[i] == 'z')
		{
			size++;
			i++;
			if (str[i] == '=')
			{
				i++;
			}
		}
		else
		{
			size++; i++;
		}
	}
	cout << size;
}
