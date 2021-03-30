#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int u,int v)
{
	return (v == 0) ? u : gcd(v, u%v);
}
int main()
{
	int n, m;
	scanf("%d:%d", &n, &m);
	int r = gcd(n, m);
	printf("%d:%d", n / r, m / r);
}