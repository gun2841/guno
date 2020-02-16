#include <iostream>
#include <string>
#include <stack>
#include <bitset>
using namespace::std;

int main()
{
	int n; string str;
	stack<char> st;
	cin >> n;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (st.empty())
		{
			st.push(str[i]);
		}
		else {
			if (str[i] == st.top()) {
				cout << "No";
				return 0;
			}
			else
				st.push(str[i]);
		}
	}
	cout << "Yes";
}

