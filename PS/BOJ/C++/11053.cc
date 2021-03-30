#include <iostream>
#include <algorithm>
using namespace::std;
int arr[1000], temp[1000];
int main()
{
	int a,n,m=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	temp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] > arr[j]) temp[i] = max(temp[i], temp[j]);
			
		}
		m = max(temp[i]++, m);
	}
	printf("%d", ++m);
	
}