#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
	long long answer = 0;
	answer = sqrt(n);
	if (answer*answer != n)
		return -1;
	return (answer+1)*(answer + 1);
}