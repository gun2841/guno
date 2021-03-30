#include <iostream>

using namespace std;

int main()
{
	long long N, ans=0, _N;
	cin >> N;
	for (int i = 1; i < N; i++){
		_N = (N + 1)*i;
		ans += _N;
	}
	cout << ans;
}