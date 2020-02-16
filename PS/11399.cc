#include <iostream>
#include <algorithm>
using namespace::std;

int main()
{
	int N;
	int arr[1001], sum=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+N);
	for (int i = 0; i < N; i++)
	{
		if (i != 0)
			arr[i] += arr[i - 1];
		sum += arr[i];
	}
	cout << sum;
}