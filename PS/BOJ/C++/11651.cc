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
using namespace::std;
struct st
{
	int x, y;
};
bool compare(st a, st b)
{
	if (a.y < b.y)
		return true;
	else if (a.y == b.y && a.x < b.x)
		return true;

	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<st> vt;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		st tmp;
		tmp.x = a; tmp.y = b;
		vt.push_back(tmp);
	}
	sort(vt.begin(), vt.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << vt[i].x << " " << vt[i].y << "\n";
	}
}