#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
 	bool answer = true;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'p' || s[i] == 'P')
		{
			cnt++;
		}
		else if (s[i] == 'Y' || s[i] == 'y')
			cnt--;
	}
	if (cnt == 0)
		answer = true;
	else
		answer = false;
	return answer;
}