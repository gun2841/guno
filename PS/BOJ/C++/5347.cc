#include <iostream>
using namespace::std;
unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	if (b == 0) return a;
	gcd(b, a%b);
}
int main()
{
	unsigned long long a, b;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%llu %llu", &a, &b);
		printf("%llu\n", a/gcd(a, b)*b);
	}
}