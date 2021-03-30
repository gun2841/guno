#include <iostream>
#include <algorithm>
using namespace::std;
int d[101][10];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= 9; i++)
		d[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			d[i][j] = 0;
			if (j - 1 >= 0)d[i][j] += d[i - 1][j - 1];
			if (j + 1 <= 9)d[i][j] += d[i - 1][j + 1];
			d[i][j] %= 1000000000;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++)ans += d[N][i];
	ans %= 1000000000;
	printf("%lld", ans);
	
}