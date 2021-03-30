#include <iostream>
#include <vector>
using namespace::std;
int main(void)
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int P, M, F, C;
		cin >> P >> M >> F >> C;
		int d, s, dcnt, scnt;
		d = dcnt = s = M / P;
		dcnt = scnt = dcnt * C;
		d += dcnt / F;
		if ((scnt - F) >= 0) s += (scnt - F) / (F - C) + 1;
		printf("%d\n", s-d);
	}
}