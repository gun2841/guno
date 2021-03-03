#include <iostream>
using namespace::std;

int main()
{
	int arr[1000], i=0,sum=0, max = 0;

	double a, b;
	scanf("%lf", &a);
	b = a;
		while (a--)
		{
			scanf("%d", &arr[i]);
			if (arr[i] > max)
				max = arr[i];
			sum += arr[i++];
		}
		printf("%0.2lf", sum / b / max * 100);
}

