#include <iostream>
#include <string>
using namespace::std;
int main()
{
	int T, r, e, c;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d", &r, &e, &c);
		if (r > (e - c))
			printf("do not advertise\n");
		else if (r == (e - c))
			printf("does not matter\n");
		else
			printf("advertise\n");
	}
}