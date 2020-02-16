#include <iostream>
#include <string>
using namespace::std;
int main()
{
	char a[10000];
	int x, i, b = 0, c = 0, t = 1;
	for (i = 0; i<100; i++)
	{
		scanf("%c", &a[i]);
		if (a[i] == ' ')
			break;
		c++;
	}
	scanf("%d", &x);
	for (i = 0; i<c; i++)
	{
		if (a[c - i - 1] >= 48 && a[c - i - 1]<58)
			b += ((a[c - i - 1] - 48)*t);
		else
			b += ((a[c - i - 1] - 55)*t);
		t = t*x;
	}
	printf("%d", b);
}
