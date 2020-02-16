#include <iostream>
#include <algorithm>
using namespace::std;
int main()
{
	int arr[4];
	char a[4];
	for (int i = 0; i < 3; i++)
		scanf("%d", arr + i);
	sort(arr, arr + 3);
	scanf("%s", &a);
	printf("%d %d %d", arr[a[0]-65], arr[a[1]-65], arr[a[2]-65]);
}