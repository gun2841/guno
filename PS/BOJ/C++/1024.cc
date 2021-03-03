#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, l;
	double temp,x;
	cin >> n >> l;

	for (int i = l; i <= 100; i++) {
		temp = n*(2.0 / i);
		x = (temp - i + 1) / 2.0;
		if (x >= 0 && ((int)x) == x) {
			for (int j = 0; j < i; j++) {
				cout << (int)x + j<< " ";
			}
			return 0;
		}
	}
	cout << "-1";
}