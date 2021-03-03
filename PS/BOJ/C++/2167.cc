#include <cstdio>
#include <algorithm>
using namespace std;
int arr[300][300];
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%d", &arr[i][j]);
	}
	int T, i, j, x, y;
	scanf("%d", &T);
	while (T--)
	{
		int sum = 0;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		for (int a = i - 1; a < x; a++)
			for (int b = j - 1; b < y; b++)
				sum += arr[a][b];

		printf("%d\n", sum);
	}
}