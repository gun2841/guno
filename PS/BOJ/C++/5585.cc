#include <iostream>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int N, cnt = 0;
	cin >> N;
	N = 1000 - N;
	cnt = cnt + N / 500;
	N %= 500;

	cnt = cnt + N / 100;
	N %= 100;

	cnt = cnt + N / 50;
	N %= 50;

	cnt = cnt + N / 10;
	N %= 10;
	cnt = cnt + N / 5;
	N %= 5;
	cnt += N;
	cout << cnt;
}