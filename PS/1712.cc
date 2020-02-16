#include <iostream>
using namespace::std;

int main()
{
	unsigned long long a, b, c,i;
	scanf("%llu %llu %llud", &a, &b, &c);
	if (c<=b)
		printf("-1");
	else {
		i = a / (c - b);
		cout << i+1;
	}
}
