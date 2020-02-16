#include <iostream>
#include <string>
using namespace::std;

int main()
{
	int A;
	int str[13];

	while (true)
	{
		scanf("%d", &A);
		if (A == 0) break;
		for (int i = 0; i < A; i++)
			scanf("%d", str + i);
		int B = A - 6;
		for (int i = 0; i <= B && i<A; i++) {
			for (int j = i + 1; j <= i +1+B && j < A; j++) {
				for (int k = j + 1; k <= j + 1 + B && k < A; k++) {
					for (int l = k + 1; l <= k + 1 + B&& l < A; l++) {
						for (int m = l + 1; m <= l + 1 + B&&m < A; m++)
							for (int n = m + 1; n <= m + 1 + B&&n < A; n++)
								printf("%d %d %d %d %d %d\n", str[i], str[j], str[k], str[l], str[m], str[n]);
					}
				}
			}
		}
		printf(" ");
	}
}