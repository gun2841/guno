#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> qu;
	int arr[10] = { 0, };
	for (int i = 0; i < priorities.size(); i++)
	{
		pair<int, int> p = make_pair(i,priorities[i]);
		qu.push(p);
		arr[priorities[i]]++;
	}
	while (!qu.empty())
	{
		int max = 0;
		for (int i = 9; i > 0; i--)
		{
			if (arr[i] != 0)
			{
				max = i; break;
			}
		}
		if (qu.front().second == max)
		{
			answer++;
            	arr[max] --;
			if (qu.front().first == location)
				return answer;
			qu.pop();
		}
		else
		{
			qu.push(qu.front());
			qu.pop();
		}
	}
	return answer;
}