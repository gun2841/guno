#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace::std;

int main()
{
	int N;
	int max = 0, min = 1000;
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int a;
		scanf("%d ", &a);
		if (a > max)
			max = a;
		if (a < min)
			min = a;
	}
	int a;
	scanf("%d", &a);
	if (a > max)
		max = a;
	if (a < min)
		min = a;

	cout << max - min;
}