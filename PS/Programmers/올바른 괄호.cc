#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	int cnt = 0;
	bool answer = true;
	if (s[0] == ')')
		return false;
	else
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				cnt++;
			else if (s[i] == ')' && cnt != 0)
				cnt--;
			else if (s[i] == ')' && cnt == 0)
				return false;
		}
	}
	if (cnt == 0)
		return answer;
	else
		return false;
}