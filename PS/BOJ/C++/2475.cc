#include <cstdio>
#include <algorithm>
using namespace std;
int main() 
{
	int a,b=0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &a);
		b = (b+ (a*a) )% 10;
	}
	printf("%d", b % 10);
}