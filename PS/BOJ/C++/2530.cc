#include <iostream>
#include <string>
using namespace::std;
int main()
{
	int hour, min, sec, add, count;
	scanf("%d %d %d", &hour, &min, &sec);
	scanf("%d", &add);
	count = hour * 3600 + min * 60 + sec + add;
	while (count > 86400)
	{
		count -= 86400;
	}
	hour = count / 3600;
	min = (count - hour * 3600) / 60;
	sec = count - hour * 3600 - min * 60;
	printf("%d %d %d", hour, min, sec);
}

