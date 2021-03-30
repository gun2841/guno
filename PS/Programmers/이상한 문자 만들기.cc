#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	int cnt = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ') {
			cnt = 1;
			continue;
		}

		if (cnt % 2 == 1) {
			s[i] = toupper(s[i]);
			cnt++;
		}
		else {
			s[i] = tolower(s[i]);
			cnt++;
		}
	}
	return s;
}