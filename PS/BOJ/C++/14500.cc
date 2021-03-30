#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
using namespace::std;
int n, m;
int arr[501][501];


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int answer = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	//ㅡ
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m - 3; j++)
		{
			int temp = 0;
			for (int k = 0; k < 4; k++)
			{
				temp += arr[i][j + k];
			}
			answer = max(answer, temp);
		}
	// ㅣ
	for (int i = 0; i < n - 3; i++)
		for (int j = 0; j < m; j++)
		{
			int temp = 0;
			for (int k = 0; k < 4; k++)
			{
				temp += arr[i + k][j];
			}
			answer = max(answer, temp);
		}

	//ㅁ
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
		{
			int temp = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
			answer = max(answer, temp);
		}
	//L , ㄱ, 아래짧
	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 1; j++)
		{
			int temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];//L
			answer = max(answer, temp);
			temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1]; //
			answer = max(answer, temp);
			temp = arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1] + arr[i + 2][j];//L 리버스
			answer = max(answer, temp);
			temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j ] + arr[i + 2][j];// 리버스
			answer = max(answer, temp);
		}
	// ㄴ, ㄱ 아래 길
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 2; j++)
		{
			int temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];//ㄴ
			answer = max(answer, temp);
			temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]; //ㄱ
			answer = max(answer, temp);
			temp = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2] + arr[i][j + 2];//ㄴ 리버스
			answer = max(answer, temp);
			temp = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i][j + 2];//ㄱ 리버스
			answer = max(answer, temp);
		}
	// 번개
	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 1; j++)
		{
			int temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			answer = max(answer, temp);
			temp = arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j];
			answer = max(answer, temp);
		}
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 2; j++)
		{
			int temp = arr[i+1][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i][j+2];
			answer = max(answer, temp);
			temp = arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+1][j+2];
			answer = max(answer, temp);
		}
	//ㅗ, ㅜ
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 2; j++)
		{
			int temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
			answer = max(answer, temp);
			temp = arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			answer = max(answer, temp);
		}
	//ㅓ,ㅏ
	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 1; j++)
		{
			int temp = arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			answer = max(answer, temp);
			temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
			answer = max(answer, temp);
		}
	cout << answer;

}