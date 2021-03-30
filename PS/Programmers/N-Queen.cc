#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
using namespace::std;
int N, cnt=0;
int chess[13];
int pl(int l)
{
	for (int i = 0; i < l; i++)
	{
		if (chess[i] == chess[l] || abs(chess[l] - chess[i]) == l - i)
		return 0;
	}
	return 1;
}
void nQ(int l)
{
	if (l == N - 1)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		chess[l + 1] = i;
		if (pl(l + 1))
			nQ(l + 1);
	}
}
int solution(int n) {
	int answer = 0;
	N = n;
	nQ(-1);
	answer = cnt;
	return answer;
}