#include <iostream>
using namespace::std;
#define max 1000001
bool prime[max];
int main()
{
	for (int i = 2; i < max; i++)
		prime[i] = true;
	for (int i = 2; i*i < max; i++)
		for (int j = 2; prime[i] && i*j < max; j++)
			prime[i*j] = false;

	int n;
	scanf("%d", &n);

	while (n) {
		for (int i = 3; i * 2 <= n; i += 2) {
			if (prime[i] && prime[n - i]) {
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
		scanf("%d", &n);
	}
}
