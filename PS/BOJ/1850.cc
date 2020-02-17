#include <iostream>

using namespace::std;

int main() {
	unsigned long long A, B;
	scanf("%lld %lld", &A, &B);
	while (B!=0) {
		unsigned long long  r = A%B;
		A = B;
		B = r; 
	}
	while(A--)
	printf("1");
}