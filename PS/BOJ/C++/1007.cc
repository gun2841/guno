#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector<pair<int, int>> vt;

int main() {
	int n;
	cin >> n;
	cout << fixed;
	cout.precision(8);
	while (n--) {
		vt.clear();
		int t;cin >> t;
		double ans = 987654321,tmp;
		for (int i = 0;i < t;i++)
		{
			int x, y;
			cin >> x >> y;
			vt.push_back(make_pair(x, y));
		}
		vector<bool> sign(t,true);
		for (int i = 0;i < t / 2;i++) sign[i] = false;
		do {
			tmp = 0;
			int mx = 0, my = 0;
			for (int i = 0;i < t;i++)
			{
				if (sign[i]) { mx += vt[i].first, my += vt[i].second; }
				else { mx -= vt[i].first, my -= vt[i].second; }
			}
			ans = min(ans, sqrt(double(mx)*mx + double(my)*my));
		} while (next_permutation(sign.begin(), sign.end()));
		cout << ans <<endl;
	}
}