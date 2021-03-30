#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long c,d;
    if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
    c = a;
    d = b;
    answer = ((d + 1)*d/2 ) - ((c -1)*c/2);
    return answer;
}