#include <iostream>
using namespace::std;

int main()
{
	int arr[101];
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a;
		int count = 0;
		scanf("%d", &a);
		for (int i = 1; i <= a; i++)
			arr[i] = 1;
		for (int i = 2; i <= a; i++)
		{
			for (int j = 1; j*i <= a; j++)
			{
				if (arr[j*i] == 0)
					arr[j*i] = 1;
				else if(arr[j*i] == 1)
					arr[j*i] = 0;
			}
		}
		for (int i = 1; i <= a; i++)
			if (arr[i] == 1)
				count++;

		printf("%d\n", count);
	}
}