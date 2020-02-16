#include <iostream>
using namespace::std;
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0;i<9;i++)
	{
		int a;
		scanf("%d", &a);
		n -=a;
	}
	printf("%d",  n);
}