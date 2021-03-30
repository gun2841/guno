#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<vector>

#include<iostream>

#include<algorithm>

#include<cmath>

using namespace std;

int main() {

	int n, m, c1, c2;

	scanf("%d %d %d %d", &n, &m, &c1, &c2);

	vector< pair<int, int> > v(n + m);

	for (int i = 0; i < n; i++) {

		scanf("%d", &v[i].first);

		v[i].second = 0;

	}

	for (int i = 0; i < m; i++) {

		scanf("%d", &v[i + n].first);

		v[i + n].second = 1;

	}

	sort(v.begin(), v.end());

	int size = v.size(), cnt = 0, min = 999999999;

	for (int i = 0; i < size - 1; i++) {

		if (v[i].second != v[i + 1].second) {

			int cmp = abs(v[i].first - v[i + 1].first);

			if (min > cmp) {

				min = cmp;

				cnt = 1;

			}

			else if (min == cmp) {

				cnt++;

			}

		}

	}

	printf("%d %d\n", abs(c1 - c2) + min, cnt);
	return 0;

}