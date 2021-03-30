#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
	int arr[10] = { 0 ,0,0,0,0,0,0,0,0,0};
	int cnt = 0;
	long long answer = 0;
	while (n)
	{
		arr[n % 10]++;
		n /= 10;
		cnt++;
	}
	for (int i = 9; i >=0; i--)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			answer *= 10;
			answer += i;
		}
	}
	return answer;
}