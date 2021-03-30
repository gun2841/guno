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
using namespace::std;
vector<int> vt;
int n;
void print()
{
	for (int i = 0; i < n; i++)
		cout << vt[i] << " ";
	cout << "\n";
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vt.push_back(i + 1);
	}
	print();
	while (next_permutation(vt.begin(), vt.end()))
	{
		print();
	}
}