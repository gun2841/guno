#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	vector<int> arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x; arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	int a, b, c, d;
	a = arr[0] * arr[1] * arr[n - 1];
	b= arr[n - 1]* arr[n - 2] * arr[n - 3];
	c = arr[n - 1] * arr[n - 2];
	d = arr[0] * arr[1];
	cout << max(max(a, b), max(c, d));
}