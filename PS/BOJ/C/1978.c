#include <stdio.h>

int main() {
	int i,N,num, check, count=0;
	scanf("%d", &N);
	while (N--)
	{
		check = 0;
		scanf("%d", &num);
		if (num == 1) {
			check = 1;
		}
		for (i = 2; i*i <= num; i++) {
			
			if (num%i == 0) {
				check = 1;
				break;
			}
		}
		if (check == 0)
			count++;
	}
	printf("%d", count);
}