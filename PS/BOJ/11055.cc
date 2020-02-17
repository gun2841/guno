#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace::std;
long arr[1001], temp[1001];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	long long max = 0;
	for (int i = 0; i < n; i++) {
		temp[i] = arr[i];
		for (int j = 0; j < i; j++)
		{
			if ((arr[j] < arr[i]) && temp[i] < temp[j] + arr[i])
			{
				temp[i] = temp[j] + arr[i];
				if (max < temp[i]) {
					max = temp[i];
				}
			}
		}
	}
	if (max == 0)
		cout << arr[0];
	else
		cout << max;

}