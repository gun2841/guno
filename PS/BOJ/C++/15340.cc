#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int solve(int C, int D)
{
	int a = 30 * C + 40 * D;
	int b = 35 * C + 30 * D;
	int c = 40 * C + 20 * D;
	return min(min(a, b), min(a, c));
}
int main()
{
	int C, D;
	while (scanf("%d %d", &C, &D)) {
		if (C == 0 && D == 0)
			break;
		cout << solve(C, D) << endl;
	}
}