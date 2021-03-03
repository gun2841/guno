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
using namespace::std;
int N, M, height[1000000];
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> height[i];

	int lo = 0, hi = 1000000000;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++)
			if(height[i] > mid)
			sum += (height[i] - mid);
		if (sum >= M) lo = mid;
		else hi = mid;
	}
	cout << lo;
}	