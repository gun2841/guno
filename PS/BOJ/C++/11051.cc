#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <stack>
using namespace::std;
int memo[1001][1001];
int main()
{
	int N, K;
	cin >> N >> K;
	for(int i = 1;i<=N;i++)
		for (int j = 0; j <= N; j++)
		{
			if (j == i || j == 0)
			{
				memo[i][j] = 1; continue;
			}
			memo[i][j] = (memo[i - 1][j] + memo[i - 1][j - 1]) % 10007;
		}
	cout << memo[N][K];
}	