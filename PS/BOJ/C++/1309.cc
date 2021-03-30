#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	int arr[100001];
	arr[0] = 1;arr[1] = 3;arr[2] = 7;arr[3] = 17;
	cin >> n;
	for (int i = 2;i <= n;i++)
	{
		arr[i] = (arr[i - 2] + arr[i - 1] * 2)%9901;
	}
	cout << arr[n]%9901;
}