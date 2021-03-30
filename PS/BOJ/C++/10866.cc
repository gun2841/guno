#include <iostream>
#include <deque>
#include <string>
using namespace::std;

int main()
{
	int test;
	deque<int> arr;
	scanf("%d", &test);
	while (test--)
	{
		string str;
		int n;
		cin >> str;
		if (str == "push_front")
		{
			scanf("%d", &n);
			arr.push_front(n);
		}
		else if (str == "push_back")
		{
			scanf("%d", &n);
			arr.push_back(n);
		}
		else if (str == "pop_front")
		{
			if (arr.empty() == 1)
				printf("-1\n");
			else {
				cout << arr.front()<<endl;
				arr.pop_front();
			}
		}
		else if (str == "pop_back")
		{

			if (arr.empty() == 1)
				printf("-1\n");
			else {
				cout << arr.back()<<endl;
				arr.pop_back();
			}
		}
		else if (str == "size")
		{
			cout << arr.size()<<endl;
		}
		else if (str == "empty")
		{
			if (arr.empty() == 1)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (str == "front")
		{
			if (arr.empty() == 1)
				printf("-1\n");
			else {
				cout << arr.front()<<endl;
			}
		}
		else if (str == "back")
		{
			if (arr.empty() == 1)
				printf("-1\n");
			else {
				cout << arr.back()<<endl;
			}
		}

	}
}