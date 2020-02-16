#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
using namespace::std;
int  temp[1001] ,vt[1001];
int main()
{
	int n,x;
	scanf("%d", &n);
	for (int i = n-1; i >=0; i--) {
		cin >> vt[i];
		temp[i] = 1;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
		{
			if (vt[i] > vt[j]) temp[i] = max(temp[i], temp[j] + 1);
		}
	}
	int ans=0;
	for (int i = 0; i < n; i++)
		ans = max(ans,temp[i]);
	cout << ans ;
}