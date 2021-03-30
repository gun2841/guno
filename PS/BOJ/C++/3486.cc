
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char* strreverse(char *string)
{
	char *s = string;
	char *left = string;
	char v;
	while (*string++);
	string = string - 2;
	while (left < string) {
		v = *left;
		*left++ = *string;
		*string-- = v;
	}
	return s;
}
int main()
{
	char a[1000], b[1000];
	int n;
	scanf("%d", &n);

	while (n--) {
		scanf("%s %s", a, b);
		strreverse(a);
		strreverse(b);
	//	 printf("%s %s", a, b);
		int c = atoi(a);
	
		int d = atoi(b);
		c += d;
		sprintf(a, "%d", c);
		strreverse(a);
		c = atoi(a);
		printf("%d\n", c);
	}
}
