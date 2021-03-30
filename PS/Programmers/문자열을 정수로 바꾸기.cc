#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string s) {
	int answer = 0;
	if (s[0] == '+')
	{
		s.erase(remove(s.begin(), s.end(), '+'),s.end());
	}
	else if (s[0] == '-')
	{
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
		answer = atoi(s.c_str());
		return 0 - answer;
	}
	answer = atoi(s.c_str());
	return answer;
}