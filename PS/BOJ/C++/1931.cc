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
struct pack {
	int start;
	int end;
};
bool compare(pack a, pack b)
{
	if (a.end == b.end)
		return a.start < b.start;
	else
		return a.end < b.end;

}
int main()
{
	vector<pack> vt;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		pack pk; pk.start = a; pk.end = b;
		vt.push_back(pk);
	}
	sort(vt.begin(), vt.end(),compare);
	int pivot = vt[0].end;
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		if (vt[i].start >= pivot)
		{
			pivot = vt[i].end;
			ans++;
		}
	}
	cout << ans;
}	
//3085