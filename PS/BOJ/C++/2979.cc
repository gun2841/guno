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
int arr[101];
int main()
{
	int a, b, c;
	int ans = 0;
	cin >> a >> b >> c;
	int x, y;
	cin >> x >> y;
	for (int i = x; i < y; i++)
		arr[i] = 1;
	cin >> x >> y;
	for (int i = x; i < y; i++)
	{
		if (arr[i] == 1)
			arr[i] = 2;
		else
			arr[i] = 1;
	}
	cin >> x >> y;
	for (int i = x; i < y; i++)
	{
		if (arr[i] == 2)
			arr[i] = 3;
		else if (arr[i] == 1)
			arr[i] = 2;
		else
			arr[i] = 1;
	}
	for (int i = 1; i <= 100; i++)
	{
	//cout << arr[i] << endl;
		if (arr[i] == 1)
			ans += a;
		else if (arr[i] == 2)
			ans += (2 * b);
		else if(arr[i] ==3)
			ans += (3 * c);
	}
	cout << ans;
}