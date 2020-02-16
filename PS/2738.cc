#include <iostream>
using namespace::std;
int arr[101];
int main()
{
	ios_base::sync_with_stdio(false);
	int N, M, K;
	
	int arr[101][101], brr[101][101];
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> brr[i][j];
			arr[i][j] += brr[i][j];
		}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}