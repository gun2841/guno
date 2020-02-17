#include <iostream>
#include <string>
using namespace::std;
int main()
{	
	int count, at, max = 0;
	for (int i = 1; i < 10; i++)
	{
		scanf("%d", &count);
		if (count > max)
		{
			max = count;
			at = i;
		}
	}
	printf("%d\n%d", max, at);
}

