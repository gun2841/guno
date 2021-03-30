#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <utility>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b; b = r;
	}
	return a;
}
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
int solution(vector<int> arr) {
	int n = arr.size();
	int answer = 0;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
		pq.push(arr[i]);
	while (pq.size() > 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		pq.push(lcm(a, b));
	}

	return pq.top();
}