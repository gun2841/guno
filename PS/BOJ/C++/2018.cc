#include <iostream>
using namespace::std;
int sum(int i, int j);
int main()
{
	int N, count = 0;
	cin >> N;
	for (int i = 1; i <= N / 2; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (sum(j, i) == N)
			{
				count++;
				break;
			}
			else if (sum(j, i) > N)
				break;
		}
	}
	cout << count+1;
}

int sum(int i, int j)
{
	return (i*(i + 1) - j*(j - 1)) / 2;
}