#include <iostream>
using namespace::std;
int main()
{
	int arr[9][9];
	int n, max =0,a,b;
	for (int i = 0;i <9;i++)
		for(int j = 0; j < 9; j ++)
		{
			scanf("%d", &n);
			if(n>max )
			{
				max = n;
				a = i  +1;
				b = j+1;
			}
		}

		printf("%d\n%d %d", max,a,b);
}