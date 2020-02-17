#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace::std;

int N, M;
int i, j;
int arr1[101][101], arr2[101][101];
int arr3[100];
int remain = 0; int abcd = 0;
void dfs(int Y, int X, bool outside[][101])
{
	if (Y < 0 || X < 0 || Y >= N || X >= M)
		return;
	if (arr1[Y][X] == 1)
		return;

	if (outside[Y][X] == true)
		return;
	outside[Y][X] = true;

	dfs(Y + 1, X, outside);
	dfs(Y, X + 1, outside);
	dfs(Y - 1, X, outside);
	dfs(Y, X - 1, outside);
}
int main()
{
	int tmp;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) {
			scanf("%d", &arr1[i][j]);
			arr2[i][j] = arr1[i][j];
			if (arr1[i][j] == 1) {
				remain++;
			}
		}
	arr3[abcd] = remain;
	while (remain != 0)
	{
		remain = 0;
		abcd++;
		bool outside[101][101] = { false };
		dfs(0, 0, outside);
		for (i = 1; i < N - 1; i++) {
			for (j = 1; j < M - 1; j++) {
				tmp = 0;
				if (arr1[i + 1][j] == 0 && outside[i + 1][j] == true)
					tmp++;
				if (arr1[i - 1][j] == 0 && outside[i - 1][j] == true)
					tmp++;
				if (arr1[i][j + 1] == 0 && outside[i][j + 1] == true)
					tmp++;
				if (arr1[i][j - 1] == 0 && outside[i][j - 1] == true)
					tmp++;

				if (tmp >= 1) {
					arr2[i][j] = 0;
				}
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				arr1[i][j] = arr2[i][j];
				if (arr1[i][j] == 1) {
					remain++;
					arr3[abcd] = remain;
				}
			}
		}
	}
	printf("%d\n%d", abcd, arr3[abcd - 1]);
	return 0;
}