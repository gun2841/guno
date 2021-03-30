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
using namespace::std;

int main() {
	ios_base::sync_with_stdio(false);
	long long N, b, c;
	long long answer = 0;
	cin >> N;
	vector<long long> a(N);
	for (long long i = 0; i < N; i++)
		cin >> a[i];

	cin >> b >> c;
	for (long long i = 0; i < N; i++)
	{
		if (a[i] > b)
		{
			a[i] -= b;
			answer++;
			answer+=(long long)ceil((double(a[i]) / double(c)));
		}
		else
		{
			answer++;
		}
	}
	cout << answer;
}