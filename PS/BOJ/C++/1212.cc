#include <iostream>
#include <string>
using namespace::std;
int str[50][3];
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (i != 0) {
			switch (s[i])
			{
			case '0':
				cout << "000";
				break;
			case '1':
				cout << "001";
				break;
			case '2':
				cout << "010";
				break;
			case '3':
				cout << "011";
				break;
			case '4':
				cout << "100";
				break;
			case '5':
				cout << "101";
				break;
			case '6':
				cout << "110";
				break;
			case '7':
				cout << "111";
				break;
			default:
				break;
			}
		}
		else
		{
			switch (s[0])
			{
			case '0':
				cout << "0";
				break;
			case '1':
				cout << "1";
				break;
			case '2':
				cout << "10";
				break;
			case '3':
				cout << "11"; break;
			case '4':
				cout << "100"; break;
			case '5':
				cout << "101"; break;
			case '6':
				cout << "110"; break;
			case '7':
				cout << "111"; break;
			default:
				break;
			}
		}
	}
}