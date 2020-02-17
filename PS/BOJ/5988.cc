#include <iostream>
#include <string>
#include <stdlib.h>
using namespace::std;

int main()
{
	string K;
	int N;

	scanf("%d", &N);

	while (N--)
	{
		cin >> K;
		char ch = K[K.size() - 1];
		if (ch % 2 == 0)
			printf("even\n");
		else
			printf("odd\n");

	}
}