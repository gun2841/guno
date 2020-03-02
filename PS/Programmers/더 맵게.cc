#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <utility>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
using namespace::std;
int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < scoville.size(); i++)
	{
		pq.push(scoville[i]);
	}
	while (1)
	{
		if (pq.top() >= K)
			break;
		else if (pq.size() == 1 || pq.empty())
			return -1;
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		pq.push(a + b * 2);

		answer++;
	}
	return answer;
}
