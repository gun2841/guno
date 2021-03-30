#include <iostream>
using namespace::std;


int main()
{
	int arr;
	int i, N;
	int sum = 0;
	cin >> N;

	for (i = 0; i < N; i++)
	{
		cin >> arr;
		sum += (arr - 1);
		sum++;
	}
	printf("%d", sum - N + 1);
}