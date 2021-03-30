#include <iostream>
using namespace::std;

int main()
{
	unsigned long long A, B, C;
	int arr[10] = { 0 };
	scanf("%llu", &A);
	scanf("%llu", &B);
	scanf("%llu", &C);
	A *= B;
	A *= C;
	arr[A % 10]++;
	while (A /= 10)
	{
		arr[A % 10]++;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
}

