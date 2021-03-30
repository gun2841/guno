#include <string>
#include <vector>

using namespace std;
string solution(int num) {
	string answer = "";
	if (num < 0)
	{
		num = 0 - num;
		if (num % 2 == 1)
			answer = "Odd";
		else
			answer = "Even";
	}
	else
	{
		if (num % 2 == 1)
			answer = "Odd";
		else
			answer = "Even";
	}
	return answer;
}