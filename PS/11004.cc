#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace::std;
int a[5000001];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	K -= 1;
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	nth_element(a, a + K, a + N);
	printf("%d", a[K]);
}
