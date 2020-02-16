#include <iostream>
using namespace::std;
int main()
{
	int out, in;
	int count = 0,max = 0;
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d", &out, &in);
		count += in;
		count -= out;
		if (count > max)
			max = count;
	}
	printf("%d", max);
}

