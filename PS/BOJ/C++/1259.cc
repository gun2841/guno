#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
#include <stack>
using namespace::std;
bool solve(string s)
{
	stack<char> st;
	int size = s.size();
	for (int i = 0; i < size/ 2; i++)
	{
		st.push(s[i]);
	}
	if (size % 2 == 1)
	{
		for (int i = (size + 1) / 2; i < size; i++)
		{
			if (st.top() != s[i])
				return false;
			st.pop();
		}
	}
	else
	{
		for (int i = size / 2; i < size; i++)
		{
			if (st.top() != s[i])
				return false;
			st.pop();
		}
	}


	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	do
	{
		cin >> s;
		if (s == "0")
			break;
		if (solve(s))
			cout << "yes";
		else
			cout << "no";
						cout << "\n";

	} while (s != "0");

}
