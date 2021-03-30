#include <iostream>
#include <algorithm>
#include <vector>
using namespace::std;


int main()
{
	int arr[51], brr[51];

	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		brr[i] = arr[i];
	}
	sort(brr, brr + N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (brr[j] == arr[i]){
				brr[j] = -1;
				arr[i] = -2;
				printf("%d ", j);
			}
		}
	

}