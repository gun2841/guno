#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ull unsigned long long

int main(int argc, char** argv)
{
	int N, M, ans = 0;

	cin >> N >> M;
	ans += N;
	while (N)
	{
		ans += N / M;
		N /= M;
		if (N < M)
			break;
	}
	cout << ans;
}