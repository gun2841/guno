#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define ull unsigned long long
ull ans[10] = { 0, };
ull sec[10] = { 0, };
void solve(ull x, ull p) {
	while (x > 0) {
		ans[x % 10] += p;
		x /= 10;
	}
}
void trans(ull n)
{
	if (n < 1) return;
	ull start = 1, p = 1;
	while (start <= n) {
		while (n % 10 != 9 && start <= n)
		{
			solve(n, p);
			n--;
		}
		if (n < start) break;
		while (start % 10 != 0 && start <= n) {
			solve(start, p);
			start++;
		}
		start /= 10;
		n /= 10;
		for (int i = 0;i < 10;i++) {
			ans[i] += (n - start + 1)*p;
		}
		p *= 10;
	}
}
int main() {
	ull a,b;
	cin >> a>>b;
	if (a > 1) { a -= 1; trans(a); }
	for (int i = 0;i < 10;i++) {
		sec[i] = ans[i];
		ans[i] = 0;
	}
	trans(b);
	ull answer = 0;
	for (int i = 0;i < 10;i++)
	{
		answer += ((ans[i] - sec[i])*(i));
		//cout << ans[i] << "  " << sec[i] << " " << answer << endl;
	}
	cout << answer;
}