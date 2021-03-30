#include <iostream>
#include <string>
using namespace::std;
int main()
{
	int T;
	string str;
	scanf("%d", &T);
	while (T--)
	{
		cin >> str;
		cout << str[0] << str[str.size() - 1] << endl;
	}

}