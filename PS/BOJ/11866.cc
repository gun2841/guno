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
	int n, k;
	cin >> n >> k;

	queue<int> q;
	vector<int> vt;

	for (int i = 0; i < n; i++)
		q.push(i + 1);

	for (int i = 0;; i++)
	{

		for (int j = 0; j < k-1; j++)
		{
			int t = q.front();
			q.pop();
			q.push(t);
		}
		int t = q.front();
		vt.push_back(t);
		q.pop();
		if (q.empty())
			break;
	}
	cout << "<";
	for (int i = 0; i < vt.size()-1; i++)
		cout << vt[i] << ", ";
	cout << vt[vt.size() - 1] << ">";

}