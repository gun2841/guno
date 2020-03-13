#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;
	int n = progresses.size();
	for (int i = 0; i < n; i++)
	{
		progresses[i] = (100 - progresses[i]) / speeds[i];
		q.push(progresses[i]);
	}
	int dx = 1;
	int pivot = q.front();
	q.pop();
	while(!q.empty()){
		if (pivot < q.front())
		{
			answer.push_back(dx);
			pivot = q.front();
			dx = 0;
		}
		dx++;
		q.pop();
	}
	answer.push_back(dx);
	return answer;
}


int main()
{
}