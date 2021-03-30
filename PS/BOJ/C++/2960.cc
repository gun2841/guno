#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
int arr[1110];
int main() {
	int N, K,cnt =0,ans;
	vector<int> vt;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		arr[i] = 1;
	for (int i = 2;; i++)
	{
		if (arr[i] == 1)
		{
			for (int j = 1; j*i <= N; j++)
			{
				if (arr[j*i] == 1) {
					arr[j*i] = 0;
					cnt++;
					if (cnt == K) {
						ans = j * i;
						cout << ans;
						return 0;
					}
				}
			}
		}
	}
	cout << ans;
}