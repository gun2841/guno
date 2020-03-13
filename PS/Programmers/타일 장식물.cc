#include <string>
#include <vector>

using namespace std;
long long arr[81];
long long tp[81];
long long solution(int N) {
	tp[1] = 1; tp[2] = 1;
	for (int i = 3; i < 81; i++)
		tp[i] = tp[i - 2] + tp[i - 1];
	long long answer = 0;
	arr[1] = 4;
	arr[2] = 7;
	arr[3] = 10;
	arr[4] = 16;
	arr[5] = 26;
	for (int i = 5; i <= N; i++)
	{
		arr[i] = tp[i] * 2 + arr[i - 1];
	}
	return arr[N];
}