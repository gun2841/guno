#include <iostream>
using namespace::std;
int main()
{
	unsigned long long arr[16][16] = { 0, };
	for (int i = 1; i <= 15; i++)
		arr[0][i - 1] = i;
	for(int i =1;i<16;i++)
		for (int j = 0; j < 16; j++) 
			for (int k = 0; k <= j; k++)
			{
				arr[i][j] += arr[i - 1][k];
			}
	int T;
	scanf("%d", &T);
	while (T--) {
		int K, N;
		scanf("%d", &K);
		scanf("%d", &N);
		printf("%lld\n", arr[K][N - 1]);
	}
	return 0;
}