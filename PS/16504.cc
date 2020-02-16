#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	unsigned long long a = 0;
	scanf("%d", &N);
	for(int i = 0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			int ans;
			scanf("%d", &ans);
			a += ans;
		}

	printf("%lld", a);
}