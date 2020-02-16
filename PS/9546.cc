#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int k;
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++)
	{
		scanf("%d", &k);
		printf("%d\n", (int)pow(2, k) - 1);
	}
}
