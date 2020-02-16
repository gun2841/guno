#include <iostream>

using namespace::std;

int main() 
{
	long long N, M, check, sum =0, count=0, temp;
	cin >> N >> M;

	for (long long i = N; i <= M; i++) {
		check = 0;
		if (i == 1)
			check = 1;
		if (i % 2 == 0 && i != 2)
			continue;
		for (long long j = 2; j*j <= i; j++) {
			if (i%j == 0) {
				check = 1;
				break;
			}
		}
		if (count == 0 && check == 0) {
			temp = i;
			count++;
		}

		if (check == 0) {
			sum += i;
			count++;
		}
	}
	if (count == 0)
		printf("-1");
	else
		cout << sum << endl << temp;
}