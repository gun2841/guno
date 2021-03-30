#include <iostream>
using namespace::std;
int arr[100];
int main()
{
	int n, ans=0, count=1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		if (arr[i] == 1)
		{
			ans += count;
			count++;
		}
		else
			count = 1;
	}
	printf("%d", ans);
}
