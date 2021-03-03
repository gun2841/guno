#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <vector>
using namespace::std;
int num[10000001];
int main()
{
	int *dp, n;
	cin >> n;
	dp = new int[n + 1];
	num[1] = 0; num[2] = 1; num[3] = 1;
	for (int i = 4; i < 1000001; i++)
	{
		int cnt = 0;
		if (i % 3 == 0) cnt = num[i /3] + 1;
		else if (i % 2 == 0) cnt = num[i / 2] + 1;

		if(( num[i-1] < cnt) ||(i%3 != 0 && i%2 != 0))
			cnt = num[i - 1] + 1;
		
		num[i] = cnt;
	}
	cout << num[n];
}