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
#include <bitset>
#include <cstdio>
#include <cstring>
using namespace::std;
int main()
{
	int n, k;
	cin >> n >> k;
	int arr[21];
	for (int i = 0; i < n - 1; i++){
		scanf("%d,", &arr[i]);
	}
	scanf("%d", &arr[n - 1]);
	for (int i = 0; i < k; i++)
	{
		int temp[21];
		for (int i = 0; i < n - 1; i++)
			temp[i] = arr[i + 1] - arr[i];

		for (int i = 0; i < n - 1; i++)
			arr[i] = temp[i];
		n -= 1;
	}
	for (int i = 0; i < n-1; i++)
	{
		cout << arr[i] << ",";
	}
	cout << arr[n - 1];
}