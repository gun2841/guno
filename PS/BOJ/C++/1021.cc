#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace::std;
int right(deque<int> dq, int pivot)
{
	int l = 0;
	do {
		int n = dq.front();
		if (n == pivot)
		{
			dq.pop_front();
			return l;
		}
		l++;
		dq.push_back(n); dq.pop_front();
	} while (1);
}
int left(deque<int> dq, int pivot)
{
	int l = 0;
	do {
		int n = dq.front();
		if (n == pivot)
		{
			dq.pop_front();
			return l;
		}
		l++;
		n = dq.back(); dq.pop_back(); dq.push_front(n);
	} while (1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	deque<int> dq;
	cin >> n >> m;
	vector<int> ans(m);
	for (int i = 0;i < m;i++)
		cin >> ans[i];
	for (int i = 0;i < n;i++)
	{
		dq.push_back(i + 1);
	}
	int answer = 0;
	for (int i = 0;i < m;i++)
	{
		int r = right(dq, ans[i]);
		int l = left(dq, ans[i]);
		if (r == 0 || l == 0) { dq.pop_front(); }
		else if (r < l) {
			answer += r;
			while(r--){
				int n = dq.front(); dq.push_back(n); dq.pop_front();
			}
			dq.pop_front();
		}
		else {
			answer += l;
			while (l--) {
				int n = dq.back(); dq.pop_back(); dq.push_front(n);
			}
			dq.pop_front();
		}
		//cout << r << " " << l << endl;
	}
	cout << answer << endl;
}
