#include <iostream>
#include <algorithm>
using namespace::std;

int main()
{
	int arr[10][4] = {
		{ 10, 10, 10, 10 },
		{ 1, 1, 1, 1 },
		{ 2, 4, 8, 6 },
		{ 3, 9, 7, 1 },
		{ 4, 6, 4, 6 },
		{ 5, 5, 5, 5 },
		{ 6, 6, 6, 6 },
		{ 7, 9, 3, 1 },
		{ 8, 4, 2, 6 },
		{ 9, 1, 9, 1 } };
	int T, a, b;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", arr[a % 10][(b + 3) % 4]);
	}
}

