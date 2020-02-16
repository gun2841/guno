#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define ull unsigned long long
int main(int argc, char** argv)
{
	while (1)
	{
		string str;
		stack<char> st;
		getline(cin, str);
		cin.clear();
		if (str[0] == '.' && str.size() == 1)
			return 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
				st.push('(');
			else if (str[i] == '[')
				st.push('[');
			else if (str[i] == ')')
			{
				if (!st.empty()) {
					if(st.top() == '(')
					st.pop();
					else
					{
						st.push(')');
					}
				}
				else
				{
					st.push(')');
				}
			}
			else if (str[i] == ']' )
			{
				if (!st.empty()) {
					if (st.top() == '[')
						st.pop();
					else
					{
						st.push(']');
					}
				}
				else
				{
					st.push(')');
				}
			}
		}
		if (st.empty() == 1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}