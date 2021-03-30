#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
	bool answer = true;
	int n = x,sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	if (x%sum == 0)
		return true;
	return false;
}