#include <iostream>
#include <string.h>
using namespace::std;

int main()
{
	char ch[10000];
	cin >> ch;
	char *ptr = strstr(ch, "JOI");
	char *pt = strstr(ch, "IOI");
	int JOI = 0, IOI = 0;
	while (ptr != NULL)
	{
		JOI++;
		ptr = strstr(ptr + 1, "JOI");
	}
	while (pt != NULL)
	{
		IOI++;
		pt = strstr(pt + 1, "IOI");
	}
	printf("%d\n%d", JOI, IOI);
	
}