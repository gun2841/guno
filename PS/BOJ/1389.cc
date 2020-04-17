#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int arr[1001][1001];
int main()
{
	int n, m;
	int cnt = 0;
	int answer = 0, sum = INF;
	cin >> n >> m;
	//arr배열 초기화
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			arr[i][j] = INF;
		}
	//입력하는 공간
	while (m--)
	{
		int start, end;
		cin >> start >> end;
		arr[start - 1][end - 1] = 1;
		arr[end - 1][start - 1] = 1;
	}

	//플로이드와샬
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}

	//arr에서는 i->j로 가는 최단거리만 남음
	/*
	for (int i = 0; i < n; i++)
	{
		answer = min(answer, arr[i][i]); // i에서 x로 , x에서 i로 최솟값
	}*/
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < n; j++)
		{
			if (i != j)
				temp += arr[i][j];
		}
		if (temp < sum) {
			sum = temp;
			answer = i;
		}
	}
	cout  << answer+1 << endl;


}