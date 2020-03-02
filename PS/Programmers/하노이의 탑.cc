#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <numeric>
using namespace::std;
vector<vector<int>> answer;
void hanoi(int n, int from, int tmp,int to)
{
	if (n == 1)
	{
		vector<int> tp;
		tp.push_back(from);
		tp.push_back(to);
		answer.push_back(tp);
	}
	else
	{
		hanoi(n - 1, from, to, tmp);
		vector<int> tp;
		tp.push_back(from);
		tp.push_back(to);
		answer.push_back(tp);
		hanoi(n - 1, tmp, from, to);
	}

}
vector<vector<int>> solution(int n) {
	hanoi(n, 1, 2, 3);
	return answer;
}