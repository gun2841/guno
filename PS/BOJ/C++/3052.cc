#include <iostream>
using namespace::std;
int arr[43];
int main()
{
	int a, b=0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a);
		arr[a % 42]++;
		if (arr[a % 42] == 1)
			b++;
	}
	printf("%d", b);
}