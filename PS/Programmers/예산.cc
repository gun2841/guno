#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <numeric>
using namespace::std;

int solution(vector<int> budgets, int M) {
	long long total = 0;
	long long n = (long long)budgets.size();
	for (long long i = 0; i < n; i++)
	{
		total += budgets[i];
	}
	sort(budgets.begin(), budgets.end());
	if (total <= M)
		return budgets[n - 1];
	else
	{
		long long sum = 0;
		for (long long i = 0; i < n; i++)
		{
			long long sub = M - sum;
			long long tmp = sub / (n - i);
			if (tmp <= budgets[i])
			{
				return tmp;
			}
			sum += budgets[i];
		}
	}
}