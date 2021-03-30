#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace::std;
int main()
{
	int n;
	string str;
	cin >> n;
	cin >> str;
	int score=0, bonus = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'O')
		{
			score += (i + 1);
			score += bonus;
			bonus += 1;
		}
		else
		{
			bonus = 0;
		}
	}
	cout << score << endl;
}