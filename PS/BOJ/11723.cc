#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace::std;
int a = 0;
int main()
{
	char cmd[10];
	string str;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%s", cmd);
		str = cmd;
		if (str == "add")
		{
			scanf("%d", &x);
			a = a | (1 << x - 1);
		}
		else if (str == "remove")
		{
			scanf("%d", &x);
			if (a & (a << x - 1))
				a = a ^ (1 << x - 1);
		}
		else if (str == "check")
		{
			scanf("%d", &x);
			if (a&(1 << x - 1))
				printf("1\n");
			else
				printf("0\n");
		}
		else if (str == "toggle")
		{
			scanf("%d", &x);
			a = a ^ (1 << x - 1);
		}
		else if (str == "all")
		{
			a = a | 0x7fffff;
		}
		else
			a = a & 0;
	}
}