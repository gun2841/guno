#include <iostream>
#include <string>
#include <vector>
using namespace::std;
int main()
{
	long long M, N, check;
	cin >> M >> N;
	for(long long i = M; i<= N;i++){
		check = 0;
		if (i == 1)
			check = 1;
		if (i % 2 == 0 && i!=2)
			continue;
		for (long long j = 2; j*j <= i; j++) {
			if (i%j == 0) {
				check = 1;
				break;
			}
		}
		if (check == 0)
			cout << i << "\n";
	}
}
