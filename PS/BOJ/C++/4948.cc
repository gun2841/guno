#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define max 246913
bool prime[max] = {  };
int main() {
	prime[0] = false, prime[1] = false;
	for (int i = 2; i < max; i++)
		prime[i] = true;
	for (int i = 2; i*i < max; i++)
		for (int j = 2; prime[i] && i*j < max; j++)
			prime[i*j] = false;

	int n;
	scanf("%d", &n);
	while (n)
	{
		int cnt = 0;
		for (int i = n+1; i <= 2 * n; i++)
		{
			if (prime[i] == true) {
				cnt++;
			}
		}
		printf("%d\n", cnt);

		scanf("%d", &n);
	}
}
