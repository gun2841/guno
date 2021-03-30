#include <iostream>
#include<queue>
using namespace::std;
int main()
{
	priority_queue<int> q;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int x;
		scanf("%d", &x);
		if (x == 0)
		{
			if (q.empty())
				printf("0\n");
			else {
				printf("%d\n", -q.top());
				q.pop();
			}
		}
		else {
			q.push(-x);
		}
	}
}