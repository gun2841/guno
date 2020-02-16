#include <iostream>
using namespace::std;

int main()
{
	int N;
	unsigned long long a = 1, b = 1;
	unsigned long long result=1;
	scanf("%d", &N);
	for (int i = 2; i < N; i++) {
		result = a + b;
		a = b;
		b = result;
	}
	printf("%lld", result);
}