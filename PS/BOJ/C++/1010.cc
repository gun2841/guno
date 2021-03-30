#include <iostream>
using namespace::std;
double combi(int a, int b);
int main(void)
{
	int t, n, m;
	double result;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		printf("%.0f\n", combi(m-n+1, m));
	}
}
double combi(int a, int b)
{
	double s = 1;
	int j = b - a + 1;
	for (int i = a; i <= b; i++) {
		s = s*(double)i / (double)j;
		j--;
	}
	return s;
}
