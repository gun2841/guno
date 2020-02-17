#include <string>
#include <vector>

using namespace std;
int solution(int n) {
	int answer = 0;
	int first=0, second=1;
	while (n--)
	{
		answer = (first + second)% 1000000007;
		first = second % 1000000007;
		second = answer % 1000000007;
	}
	return answer;
}