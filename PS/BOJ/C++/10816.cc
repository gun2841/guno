#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace::std;

int main()
{
	vector<int> a;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end(), less<int>());
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x; scanf("%d", &x);
		printf("%d ", upper_bound(a.begin(), a.end(), x)-lower_bound(a.begin(),a.end(),x));
		
	}
	
}