#include <iostream>
#include <algorithm>
using namespace::std;
int d[1001];
int main()
{
	int p[1001];
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++)
			d[i] = max(d[i], d[i - j] + p[j]);
	}
	printf("%d", d[N]);
}