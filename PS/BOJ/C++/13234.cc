#include <iostream>
#include <string>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	string str[3];
	cin >> str[0] >> str[1] >> str[2];
	if(str[1] == "AND")
	{ 
		if (str[0] == str[2] && str[0] == "true")
			cout << "true";
		else
			cout << "false";
	}
	else
	{
		if (str[0] == str[2] && str[0] == "false")
			cout << "false";
		else
			cout << "true";
	}
}