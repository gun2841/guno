#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int arr[1001][1001];
int brr[1001][1001];
bool check[1001][1001];
int main()
{
	int n, m, x;
	int cnt = 0;
	int answer = 0;
	cin >> n >> m >> x;
	//arr배열 초기화
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			arr[i][j] = INF;
			brr[i][j] = i == j ? 0 : INF;
			check[i][j] = false;
		}
	//입력하는 공간
	while (m--)
	{
		int start, end, t;
		cin >> start >> end >> t;
		arr[start - 1][end - 1] = t;
		brr[start - 1][end - 1] = t;
		if (check[start - 1][end - 1])
			cnt++;
		else
			check[start - 1][end - 1] = true;
	}

	//플로이드와샬
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				brr[i][j] = min(brr[i][j], brr[i][k] + brr[k][j]);
			}

	//arr에서는 i->j로 가는 최단거리만 남음
	for (int i = 0; i < n; i++)
	{
		answer = max(answer, arr[i][x-1] + arr[x-1][i]); // i에서 x로 , x에서 i로 최솟값
	}
	cout << "초기화X   " << answer << endl;


	//////////////////////////////
	answer = 0;
	for (int i = 0; i < n; i++)
	{
		answer = max(answer, brr[i][x - 1] + brr[x - 1][i]); // i에서 x로 , x에서 i로 최솟값
	}
	cout << "초기화    " << answer << endl;
	cout << cnt;

}