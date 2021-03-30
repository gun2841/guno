#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
using namespace std;
int arr[100001];
int main() {
	//ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	queue<int> qu;
	for (int i = 1; i <= t; i++)
	{
		qu.push(i);
	}
	while (qu.size() != 1)
	{
		qu.pop();
		qu.push(qu.front());
		qu.pop();
	}
	cout << qu.front();
}