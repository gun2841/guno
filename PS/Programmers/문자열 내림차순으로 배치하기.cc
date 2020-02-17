#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(char a, char c)
{
	if (a > c)
		return true;
	else
		return false;
}
string solution(string s) {
	string answer = "";
	sort(s.begin(), s.end(),compare);
	answer = s;
	return answer;
}	