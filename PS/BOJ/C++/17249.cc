#include <iostream>
#include <string>
#include <stack>
#include <bitset>
using namespace::std;
int main()
{
	string str;
	cin >> str;
	int len = str.size();
	int left = 0, right = 0; bool check = true;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '@' && check)
			left++;
		else if (str[i] == '@' && !check)
			right++;

		if (str[i] == ')')
			check = false;
	}
	cout << left << " " << right;
}

