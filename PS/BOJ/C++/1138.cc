#include <iostream>
using namespace::std;
int main()
{
	int arr[10] = { 0 };
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		int t, j = 0;
		scanf("%d", &t);

		while (t) t -= arr[j++] ? 0 : 1;
		while (arr[j]) j++;
		arr[j] = i + 1;
	}
	for (int i = 0; i < N; i++) printf("%d ", arr[i]);
}


