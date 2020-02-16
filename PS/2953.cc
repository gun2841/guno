#include <iostream>
#include <string>
using namespace::std;

int main()
{
	int arr[5][5], sum[5] = { 0,0,0,0,0 };
	int top, temp;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
		{
			sum[i] += arr[i][j];
		}
	top = sum[0];
	temp = 0;
	for (int i = 1; i < 5; i++) {
		if (top < sum[i])
		{
			top = sum[i];
			temp = i;
		}
	}
	cout << temp+1 << " " << top;
}