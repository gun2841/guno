#include <stdio.h>

int main() {
	int  N, count = 0;
	scanf("%d", &N);
	while (N != 1) {
		if (N % 2 == 1)
			count++;

		N = N / 2;
	}
	printf("%d", count+1);
}