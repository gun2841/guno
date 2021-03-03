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
#include <stack>
using namespace::std;

int main()
{
	long long arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
	string a, b;
	cin >> a >> b;
	long long ans = 0;

	for (int i = 0; i < a.size(); i++)
	{
		int pivot = a[i] - '0';
		long long temp = 0;
		if (arr[pivot] == 0) {
			for (int j = 0; j < b.size(); j++)
			{
				int differ = b[j] - '0';
				temp += (pivot * differ);
				ans += (pivot * differ);
			}
			arr[pivot] = temp;
		}
		else
		{
			ans += arr[pivot];
		}
	}
	cout << ans;
}