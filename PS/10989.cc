#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;
int main()
{
	int count[10001] = { 0 };
	int N, num;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &num);
		count[num]++;
	}
	for (int i = 1; i < 10001; i++)
	{
		if (count[i] != 0)
			for (int j = 0; j < count[i]; j++)
				printf("%d\n", i);
	}
}