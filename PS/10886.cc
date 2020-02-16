#include <iostream>
using namespace::std;

int main()
{
	int T;
	int a, cnt0 = 0, cnt1 = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &a);
		if (a == 1)
			cnt1++;
		else
			cnt0++;
	}
	if (cnt0 > cnt1)
		printf("Junhee is not cute!");
	else
		printf("Junhee is cute!");
}