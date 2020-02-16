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
using namespace::std;

int main()
{
	bitset<20> bt;
	int arr[20],ans = 0;
	int n, S;
	cin >> n >> S;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 1; i < (1 << n); i++)
	{
		int sum = 0;
		for (int k = 0; k < n; k++)
			if (i & (1 << k))
				sum += arr[k];

		if (sum == S)
			ans += 1;
	}
	cout << ans;
}