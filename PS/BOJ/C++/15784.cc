#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;
int arr[1001][1001];
int main()
{
	int N, x, y;
	cin >> N >> x >> y;
	for(int i =0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	for (int i = 0; i < N; i++)
	{
		if (arr[x - 1][i] > arr[x - 1][y - 1])
		{
			cout << "ANGRY";
			return 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (arr[i][y-1] > arr[x - 1][y - 1])
		{
			cout << "ANGRY";
			return 0;
		}
	}
	cout << "HAPPY";
}