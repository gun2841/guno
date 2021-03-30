#include <iostream>
#include <algorithm>
using namespace::std;
int arr[10000];
int main()
{
	int N;
	int limit, total=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		total += arr[i];
	}
	sort(arr, arr + N);
	scanf("%d", &limit);
	if (total <= limit)
		printf("%d", arr[N - 1]);
	else
	{
		int sum = 0;

		for (int i = 0; i < N; i++) {
			int sub = limit - sum;

			int tmp = sub / (N - i);
			if (tmp <= arr[i]) {
				printf("%d\n", tmp);
				return 0;
			}

			sum += arr[i];
		}
	}

}