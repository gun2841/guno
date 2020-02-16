#include <iostream>
using namespace::std;
int main()
{
	int arr[101] = { 0 };
	int N, M;
	scanf("%d %d", &N, &M);
	while (M--)
	{
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);

		for (int a = i; a <= j; a++)
		{
			arr[a] = k;
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", arr[i]);
}