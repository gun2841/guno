#include <iostream>
using namespace std;
#define max(a,b)( a > b ? 1:0)
int main() {
	unsigned int a, b;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;
		if (max(a, b) == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
}