
#include <iostream>
#include <algorithm>
using namespace::std;
int main()
{
	int S, K, H;
	scanf("%d %d %d", &S,&K,&H);
	if (S + K + H >= 100)
	{
		printf("OK");
		return 0;
	}
	else
	{
		if (S < K)
		{
			if (S < H)
				printf("Soongsil");
			else if (S > H)
				printf("Hanyang");
		}
		else if (S > K)
		{
			if(K>H)
				printf("Hanyang");
			else if( K<H)
			printf("Korea");
		}
	}
}