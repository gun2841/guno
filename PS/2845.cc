#include <iostream>
#include <string>
using namespace::std;
int main()
{
	int L, P, arr[5];
	scanf("%d %d", &L, &P);
	L *= P;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", arr + i);
		arr[i] -= L;
	}
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
}