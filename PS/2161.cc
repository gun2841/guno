#include <iostream>
#include <queue>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++)
		q.push(i + 1);

	while (!q.empty())
	{
		if (q.size() == 1)
			break;
		cout << q.front() << " ";
		q.pop();
		if (q.size() == 1)
			break;
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}
