#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int main() {
	unsigned long long n;
	unsigned long long mod = 1000000;
	unsigned long long p = mod / 10 * 15;
	vector<int> vt(p);
	cin >> n;
	vt[0] = 0; vt[1] = 1;
	for (int i = 2;i < p;i++) {
		vt[i] = vt[i - 1] + vt[i - 2];
		vt[i] %= mod;
	}
cout<< vt[n%p];
	
}
