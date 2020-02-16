#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstring>
using namespace::std;
struct circle_qu
{
	int front;
	int rear;
	void move(int L)
	{
		front += L;
		if (front > rear)
			front -= rear;
	}
	void R_move(int L)
	{
		front -= L;
		if (front < 1)
			front += rear;
	}
}qu;
int arr[1001] = { 0, };
int main()
{
	int n, m, l,cnt = 0;
	cin >> n >> m >> l;
	qu.front = 1;
	qu.rear = n;
	while (1)
	{
		arr[qu.front]+=1;
		if (arr[qu.front] == m)
			break;

		cnt++;
		if (arr[qu.front] % 2 == 1)
			qu.move(l);
		else
			qu.R_move(l);
	}
	cout << cnt;
}