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
struct st
{
	int num; // 원래 숫자
	int first = 99;
	int second = 99;
	int third = 99;
	int forth = 99;
	void number()
	{
		int d = num;
		if (d > 999)
		{
			first = 1;
			second = 0;
			third = 0;
			forth = 0;
		}
		else if (d > 99)
		{
			first = d / 100;
			second = (d % 100) / 10;
			third = d % 10;
			forth = first;
		}
		else if (d > 9)
		{
			first = d / 10;
			second = d % 10;
			third = first;
			forth = second;
		}
		else
		{
			first = d;
			second = first;
			third = first;
			forth = first;
		}
	}
};

bool compare(st a, st b)
{
	if (a.first > b.first)
		return true;
	else if (a.first == b.first)
	{
		if (a.second > b.second)
			return true;
		else if (a.second == b.second)
		{
			if (a.third > b.third)
				return true;
			else if (a.third == b.third)
			{
				if (a.forth > b.forth)
					return true;
				else if (a.forth == b.forth)
				{
					if (a.num > b.num)
						return true;
				}
			}
		}
	}

	return false;
}
string solution(vector<int> numbers) {
	string answer = "";
	int n = numbers.size();
	vector<st> vt;
	for (int i = 0; i < n; i++)
	{
		st s;
		s.num = numbers[i];
		s.number();
	
		vt.push_back(s);
	}
	sort(vt.begin(), vt.end(), compare);
	for (int i = 0; i < vt.size(); i++)
	{
		answer += to_string(vt[i].num);
	}
	if (answer[0] == '0')
		return "0";
	return answer;
}
void main()
{
	vector<int> vt;
	int s;
	cin >> s;
	vt.push_back(20);
	vt.push_back(20);
	vt.push_back(200);
	//vt.push_back(0);
	cout << solution(vt);
}