#include <iostream>
#include <set>
using namespace::std;
int N;
int main()
{
	set<int> vis;
	cin >> N;
	while (N > 1) {
		if (vis.count(N)) { printf("UNHAPPY"); return 0; }
		vis.insert(N);
		int nxt = 0;
		for (int v = N; v; v /= 10)
			nxt += (v % 10)*(v % 10);
		N = nxt;
	}
	printf("HAPPY");
}
