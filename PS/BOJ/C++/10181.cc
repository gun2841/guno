#include <iostream>
using namespace::std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (true)
	{
		int a;
		cin >> a;
		if (a == -1)
			break;
		int sum = 0;
		int count = 0;
		int cnt = 1;
		for (int i = 1; i < a; i++) {
			if (a%i == 0) {
				sum += i;
				count++;
			}
		}
		if (sum == a) {
			cout << a  << " = ";
			for (int i = 1; i < a; i++) {
				if (a%i == 0 && cnt != count) {
					cout << i << " + ";
					cnt++;
				} else if (cnt == count && a%i == 0)
					cout << i << endl;
			}
		} else cout << a  << " is NOT perfect." << endl;
	}
}