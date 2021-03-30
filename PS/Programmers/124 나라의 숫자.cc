#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	char num[3] = { '1','2','4' };
	int quo = -1, remainder;
	while (quo != 0)
	{
		quo = (n - 1) / 3;
		remainder = (n - 1) % 3;
		answer = num[remainder] + answer;
		n = quo;
	}
	return answer;
}