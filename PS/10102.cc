#include <iostream>
#include <string>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	int d; cin >> d;
	int a=0, b=0;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'A')
			a++;
		else if (str[i] == 'B')
			b++;
	}
	if (a > b)
		cout << "A";
	else if (a < b)
		cout << "B";
	else
		cout << "Tie";
}