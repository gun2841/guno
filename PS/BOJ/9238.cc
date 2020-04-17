#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int  n;
double r;
vector<int> vt;
int solve(int k, double curmin, double curmax, int cuts)
{
	if (k == n)
		return cuts;

	double absMax = curmin / r;
	double absMin = curmax * r;
	int low = (int)ceil(vt[k] / absMax);
	int high = (int)(vt[k] / absMin);
	if (k == 0)
	{
		low = 1;
		high = vt[0];
	}
	for (int i = low; i <= high; i++)
	{
		double n = vt[k] / i;

		if (k == 0) curmin = n;
		if (k == 0) curmax = n;

		int ans = solve(k + 1, min(curmin, n), max(curmax, n), cuts + i - 1);
		if (ans != -1)
			return ans;
	}
	return -1;
}
int main()
{
	cin >> r >> n;
	vt.resize(n);
	for (int i = 0; i < n; i++)
		cin >> vt[i];

	sort(vt.begin(), vt.end());

	cout << solve(0, vt[0], vt[0], 0);
}