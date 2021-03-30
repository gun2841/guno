#include <iostream>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << N << " ";
	while (N != 1) {
		if (N % 2 == 0)
		{
			N /= 2;
			cout << N << " ";
		}
		else
		{
			N = 3 * N + 1;
			cout << N << " ";
		}
	}
}