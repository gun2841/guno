#include <iostream>
#include <string>
using namespace::std;

int main() 
{
	char s[32];
	int n;
	cin >> n;
	cin.ignore(n, '\n');
	while (n--)
	{
		cin.getline(s, 32);
		if (s[0] > 96 && s[0] < 123)
		{
			s[0] -= 32;
		}
		cout << s << endl;
	}
}