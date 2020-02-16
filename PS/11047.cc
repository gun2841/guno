#include <iostream>
#include <algorithm>
using namespace::std;

int main()
{
	int N, K, _coin=0;
	scanf("%d %d", &N, &K);
	int coin[10];
	for (int i = 0; i < N; i++)
		scanf("%d", &coin[i]);
	int i = 1;
	while (K>= coin[0])
	{
		if (K >= coin[N - i])
		{
			K -= coin[N - i];
			_coin++;
		}
		else
			i++;
	}
	cout << _coin;
}