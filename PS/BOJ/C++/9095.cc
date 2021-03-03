#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <vector>
using namespace::std;
int main()
{
	int arr[11] = { 1,2,4 };
	for (int i = 3; i < 11; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << arr[n - 1]<< "\n";
	}
}