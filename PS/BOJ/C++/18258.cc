#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <cstring>
#include <set>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int front = 0, rear = 0;
	int pivot = 0;
	int n;
	cin >> n;
	vector<int> vt(n);
	while (n--)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			int t; cin >> t;
			vt[pivot] = t;
			pivot++;
			rear++;
			continue;
		}
		else if (str == "pop")
		{
			if (front == rear)
				cout << "-1";
			else
			{
				cout << vt[front];
				front++;
			}
		}
		else if (str == "size")
		{
			cout << rear - front;
		}
		else if (str == "empty")
		{
			if (front == rear)
				cout << "1";
			else
				cout << "0";
		}
		else if (str == "front")
		{
			if (front == rear)
				cout << "-1";
			else
				cout << vt[front];
		}
		else if (str == "back")
		{
			if (front == rear)
				cout << "-1";
			else
				cout << vt[rear - 1];
		}
		cout << "\n";
	}
}