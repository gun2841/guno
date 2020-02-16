#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	int k, s;
	cin >> k >> s;
	cin.ignore();
	getline(cin, str);
	k %= 26;
	for (int i = 0; i < s; i++)
	{
		if (str[i] == '.' || str[i] == ' ' || str[i] == ',')
			continue;

		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += k;
			if (str[i] > 90)
				str[i] -= 26;
		}
		else if (str[i] >= 97 && str[i] <= 122)
		{
			int a = str[i];
			a += k;
			if (a > 122)
				a -= 26;
			str[i] = a;
		}
	}
	cout << str;
}