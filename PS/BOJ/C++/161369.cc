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
using namespace::std;
int arr[200002][26];
void insert(char ch,int i)
{
	for (int idx = 0; idx < 26; idx++)
	{
		if(idx == ch-'a')
			arr[i + 1][idx] = arr[i][idx]+1;
		else
			arr[i + 1][idx] = arr[i][idx];
	}
}
int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		insert(str[i], i);
		//cout << str[i] - 'a' << endl;
	}
	int q;
	scanf("%d",&q);
	getchar();
	for (int i = 0; i < q; i++)
	{
		char c; int a, b;
		scanf("%c %d %d", &c, &a,&b);

		getchar();
		int d = arr[b + 1][c - 'a'] - arr[a][c - 'a'];
		printf("%d\n",d);
	}
}
