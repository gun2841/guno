#include <iostream>
#include <vector>
#include <string>
using namespace::std;


int main()
{
	string cmd;
	vector<int> queue;
	int n;
	int a;
	scanf("%d", &n);
	while (n--)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			scanf("%d", &a);
			queue.push_back(a);
		}
		else if (cmd == "pop")
		{
			if (queue.empty() == 0)
			{
				cout << queue.front() << endl;
				queue.begin() = queue.erase(queue.begin());
			}
			else
				cout << "-1" << endl;
		}
		else if (cmd == "size")
		{
			cout << queue.size() << endl;
		}
		else if (cmd == "empty")
		{
			if (queue.empty() == 1)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (cmd == "front")
		{
			if (queue.empty() == 0)
				cout << queue.front() << endl;
			else
				cout << "-1" << endl;
		}
		else if (cmd == "back")
		{
			if (queue.empty() == 0)
				cout << queue.back() << endl;
			else
				cout << "-1" << endl;
		}
	}
}
