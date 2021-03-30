#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace::std;
int arr[1003][1003];
int M, N;
void solve(int a, int b) {
	if (a < 0 || b < 0 || a> M-1 || b> N-1)
		return;
	if (arr[a][b] == 1)
		return;
	else if (arr[a][b] == 2)
		return;
	else if (arr[a][b] == 0)
		arr[a][b] = 2;
	solve(a+1,b); solve(a-1, b); solve(a, b+1); solve(a, b-1);
	return ;
}
int main()
{
	int d; bool checker = false;
	cin >> M >> N;
	for (int i = 0; i < M; i ++ )
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &arr[i][j]);
	}

	for (int i = 0; i < N; i++)
		solve(0, i);
	for (int i = 0; i < N; i++)
	{
		if (arr[M - 1][i] == 2)
			checker = true;
	}
	if (checker)
		cout << "YES";
	else
		cout << "NO";
		
}