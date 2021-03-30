#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace::std;
int main()
{
	int N;
	scanf("%d", &N);
	int arr[16] = { 1 };
	if (N % 2 == 1) {
		printf("0");
		return 0;
	}
	else
	{
		N /= 2;
		for (int i = 1; i <= N; i++)
		{
			arr[i] += arr[i - 1] * 3;
			for (int j = 2; j <= i; j++)
				arr[i] += arr[i - j] * 2;
		}
	}
	printf("%d", arr[N]);
}