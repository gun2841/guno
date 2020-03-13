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

struct sta
{
	string str;
	int strike;
	int ball;
};
vector<sta> vt(100);
vector<string> a;
int n;
int solve(string st)
{
	for (int i = 0; i < n; i++)
	{
		int s = 0, b = 0;
		if (st[0] == vt[i].str[0])
			s++;
		if (st[1] == vt[i].str[1])
			s++;
		if (st[2] == vt[i].str[2])
			s++;
		if (st[0] == vt[i].str[1] || st[0] == vt[i].str[2])
			b++;
		if (st[1] == vt[i].str[0] || st[1] == vt[i].str[2])
			b++;
		if (st[2] == vt[i].str[0] || st[2] == vt[i].str[1])
			b++;

		if (s != vt[i].strike || b != vt[i].ball)
			return 0;
	}
	return 1;
}
int solution(vector<vector<int>> baseball) {
	int answer = 0;
	n = baseball.size();
	for (int i = 0; i < n; i++)
	{
		vt[i].str = to_string(baseball[i][0]);
		vt[i].strike = baseball[i][1];
		vt[i].ball = baseball[i][2];
	}
	
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			for (int k = 1; k <= 9; k++)
			{
				if (i == j || j == k || i == k)
					continue;

				int d = i * 100 + j * 10 + k;
				a.push_back(to_string(d));
			}

	for (int i = 0; i < a.size(); i++)
	{
		answer += solve(a[i]);
	}
	return answer;
}