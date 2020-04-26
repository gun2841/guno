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
#include <bitset>
#include <stack>
using namespace::std;
#define max 10000110
bool prime[max];
int main()
{
	prime[0] = true;
	prime[1] = true;

	for (int i = 2; i < max; i++)
		prime[i] = true;
	for (int i = 2; i * i < max; i++)
		for (int j = 2; prime[i] && i * j < max; j++)
			prime[i * j] = false;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		int a;
		cin >> a;
		int cnt = 0;
		for (int i = 2; i * 2 <= a; i ++) {
			if (prime[i] && prime[a - i]) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}