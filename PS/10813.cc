#include <iostream>
using namespace::std;
int arr[101];
void swap(int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		arr[i] = i;
	while (M--)
	{
		int i, j;
		scanf("%d %d", &i, &j);
		swap(i, j);
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", arr[i]);
}