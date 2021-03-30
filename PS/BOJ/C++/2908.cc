#include <iostream>
#include <string>

using namespace::std;
string reverse(string str);
int main()
{
	string str, str1;
	cin >> str >> str1;
	str = reverse(str);
	str1 = reverse(str1);
	int a = atoi(str.c_str());
	int b = atoi(str1.c_str());
	if (a > b)
		cout << a;
	else
		cout << b;
}
string reverse(string str)
{
	string reverse;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		reverse.push_back(str[i]);
	}
	return reverse;
}