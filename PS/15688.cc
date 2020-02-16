#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace::std;
int arr[1000011][2];
int brr[1000011][2];
int main()
{
	int n;
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		int a; scanf("%d", &a);
		if (a >= 0) {
			if (arr[a][0] != 1) {
				arr[a][0] = 1; arr[a][1] = 1;
			}
			else {
				arr[a][1]++;
			}
		}
		else
		{
			a = abs(a);
			if (brr[a][0] != 1) {
				brr[a][0] = 1; brr[a][1] = 1;
			}
			else {
				brr[a][1]++;
			}
		}
	}
	for (int i = 1000000; i >0; i--)
	{
		if (brr[i][0] == 1)
		{
			for (int j = 0; j < brr[i][1]; j++)
				printf("%d\n", 0-i);
		}
	}
	for (int i = 0; i < 1000001; i++)
	{
		if (arr[i][0] == 1)
		{
			for (int j = 0; j < arr[i][1]; j++)
				printf("%d\n", i);
		}
	}
}