#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace::std;
int T, M, N, K,x,y, i,j,cnt;
int map[50][50] = { 0 };
void DP(int i, int j) {
	map[i][j] = 0;
	if (i && map[i - 1][j]) DP(i - 1, j);
	if (i != N - 1 && map[i + 1][j]) DP(i + 1, j);
	if (j && map[i][j - 1]) DP(i, j - 1);
	if (j != M - 1 && map[i][j + 1]) DP(i, j + 1);
	return;
}
int main()
{
	scanf("%d", &T);

	while (T--)
	{
		memset(map, 0, 2500);
		scanf("%d %d %d", &M, &N, &K);
		for (cnt =  i = 0; i < K; i++){
				scanf("%d %d", &x,&y);
				map[y][x] = 1;
			}
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (map[i][j]) {
					cnt++;
					DP(i,j);
				}
			}
		}
		printf("%d\n", cnt);
	}
}