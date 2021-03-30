#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace::std;
int main()
{
	int N,T;
	scanf("%d", &T);
	while (T--) {
		long long arr[101] = { 1 };
		arr[0] = 1; arr[1] = 1; arr[2] = 1; arr[3] = 2; arr[4] = 2;arr[5]=3;
		scanf("%d", &N);

		for (int i = 6; i <= N; i++)
		{
			arr[i] = arr[i - 2] + arr[i - 3];
		}

		cout << arr[N - 1] << endl;
	}
}