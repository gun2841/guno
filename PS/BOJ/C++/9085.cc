#include <iostream>
using namespace::std;
int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int d, sum = 0;
		scanf("%d",&d);
		for(int i = 0;i<d;i++)
		{
			int num;
			scanf("%d", &num);
			sum+=num;
		}
		printf("%d\n", sum);
	}
}