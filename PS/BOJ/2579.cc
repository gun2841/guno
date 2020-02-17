#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace::std;
int d[10001];
int main()
{
	int a[10001];
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	d[1] = a[1];
	d[2] = max(a[1] + a[2],a[2]);
	d[3] = max(a[1] + a[3], a[2] + a[3]);
	for (int i = 4; i <= n; i++) {
		d[i] = max(d[i - 2] + a[i], d[i - 3] + a[i - 1] + a[i]);
	}
	printf("%d", d[n]);
}