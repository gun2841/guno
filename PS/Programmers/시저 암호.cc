#include <string>
#include <vector>

using namespace std;
string solution(string s, int n) {
	string answer = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 32)
		{
			continue;
		}
		if (s[i] < 91)
		{
			s[i] = (((s[i] - 65) + n) % 26) + 65;
		}
		else if (s[i] > 96)
		{
			s[i] = (((s[i] - 97) + n) % 26) + 97;
		}
	}
	return s;
}