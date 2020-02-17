#include <iostream>
using namespace::std;

int main()
{
	int T, N,K,candy,count;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		count = 0;
		while (N--)
		{
			scanf("%d", &candy);
			count = count + candy / K;
		}
		cout << count<< endl;
	}
}
