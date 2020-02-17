#include <string>
#include <vector>

using namespace std;
int solution(int n) {
	int answer = 0;
	for (int i = 1; i < (n+1) / 2; i++)
	{
		int sum = 0;
		for (int j = 0;j>-1; j++)
		{
			sum += (i + j);
			if (sum == n)
			{
				answer++;
			}
			else if (sum > n)
				break;
		}
	}
	return answer+1;
}