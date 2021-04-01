#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
int main() {
	int n, k,cnt =0;
	ll prev=-1;
	cin >> k >> n;
	vector<ll> vt(k);
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (int i = 0;i < k;i++) { cin >> vt[i]; pq.push(vt[i]); }
	while (1)
	{
		if (cnt == n) break;
		ll tmp = pq.top();
		if (tmp == prev) { pq.pop(); continue; }
		else {
			prev = tmp;
			for (int i = 0;i < k;i++) {
				ll ans = tmp * vt[i];
				if (ans > 2147483648) {
					continue;
				}
				else {
					pq.push(ans);
				}
				if (pq.top() % vt[i] == 0) break;
			}
			cnt++;
		}

	}
	cout << pq.top();
}