#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	int a = 0, b = 1;
	if (n == 0)
		return 0;
	for (int i = 1; i < n; i++)
	{
		answer = (a + b)% 1234567;
		a = b% 1234567;
		b = answer% 1234567;
	}
	return answer;
}