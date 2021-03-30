#include <iostream>
#include <algorithm>
using namespace::std;

int main()
{
	int num[10], sum = 0, max = 0, check[110] = { 0 };
	for (int i = 0; i < 10; i++){
		scanf("%d", num + i);
		sum += num[i];
		check[num[i] / 10-1]++;
	}
	for (int i = 0; i < 100; i++)
		if (check[i] > max)
			max = i;

	printf("%d\n%d", sum / 10, (max+1)* 10);
}

