#include <iostream>
#include <string>
#include <stack>
using namespace::std;

int main()
{
	string str;
	stack<char> sign;
	cin >> str;
	int idx = 0;
	char ans[1001];
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') {
			ans[idx++] = str[i];
		}
		else {
			if (str[i] == '('){
				sign.push(str[i]);
			}
			else if (str[i] == ')') {
				while (sign.top() != '(')
				{
					ans[idx++] = sign.top();
					sign.pop();
				}
				sign.pop();
			}
			else if (str[i] == '*' || str[i] == '/')
			{
				while (!sign.empty() && (sign.top() == '*' || sign.top() == '/')) {
					ans[idx++] = sign.top();
					sign.pop();
				}
				sign.push(str[i]);
			}
			else if (str[i] == '+' || str[i] == '-')
			{
				while (!sign.empty() && sign.top() != '(') {
					ans[idx++] = sign.top();
					sign.pop();
				}
				sign.push(str[i]);
			}
		}
	}
	while (!sign.empty())
	{
		ans[idx++] = sign.top();
		sign.pop();
	}
	ans[idx] = '\0';
	for (int i = 0; i < idx; i++)
	{
		cout << ans[i];
	}
}