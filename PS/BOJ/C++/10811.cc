#include <iostream>
using namespace::std;
int arr[101];
void reverse(int a, int b)
{
	int temp;
	int l = (b + a);
	if (a == b)
		return;
	for (int i = b; i > l / 2; i--)
	{
		temp = arr[i];
		arr[i] = arr[a];
		arr[a++] = temp;
	}
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
		reverse(i, j);
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", arr[i]);
}