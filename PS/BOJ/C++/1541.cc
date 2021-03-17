#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	string str,num = "";
	cin >> str;
	int ans = 0, state = 0;
	for (int i = 0;i <= str.size();i++)
	{
		if (isdigit(str[i]))
		{
			num += str[i];
		}
		else
		{
			if (state == 0)
			{
				ans += atoi(num.c_str());
				if (str[i] == '-')
					state = 1;
			}
			else  if(state == 1){
				ans -= atoi(num.c_str());
			}
			num.clear();

		}
	}
	cout << ans;
}
