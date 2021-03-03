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

int arr[21][21];
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n ;
	int ans = 1000000000;
	vector<bool> check;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n / 2; i++)
		check.push_back(false);
	for (int i = 0; i < n / 2; i++)
		check.push_back(true);


	do
	{
		vector<int> first;
		vector<int> second;
		for (int i = 0; i < n; i++)
		{
			if (check[i])
				first.push_back(i);
			else
				second.push_back(i);
		}
		int first_sum = 0;
		int second_sum = 0;
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				if (i == j)
					continue;
				first_sum += arr[first[i]][first[j]];
			}
		}
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				if (i == j)
					continue;
				second_sum += arr[second[i]][second[j]];
			}
		}
		ans = min(ans, abs(first_sum - second_sum));
	} while (next_permutation(check.begin(), check.end()));

	cout << ans;
}