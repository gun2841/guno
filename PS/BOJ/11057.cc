#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	int N;
	cin >> N;
	int arr[10] = { 1,1,1,1,1,1,1,1,1,1};
	int ans;
	for (int i = 1; i < N; i++)
	{
		ans = 0;
		for (int j = 1; j <= 9; j++)
		{
			arr[j] = (arr[j] + arr[j - 1]) % 10007;
			ans = (ans + arr[j]) % 10007;
		}
	}
	if (N == 1)
		cout << 10;
	else
	cout << (ans +1)%10007;
}