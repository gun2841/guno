#include <string>
#include <vector>
#include <sstream>
using namespace::std;

string solution(string s) {
	string answer = "";
	bool first = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (first)
		{
			if (islower(s[i]))
				s[i] -= 32;
			first = false;
		}
		else if (!first)
		{
			if (isupper(s[i]))
				s[i] += 32;
		}
		 
        if (s[i] == ' ')
		{
			first = true;
			continue;
		}
	}
	return s;
}