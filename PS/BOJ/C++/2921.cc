#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int N, add = 6, ans = 3;
	int arr[1000];
	scanf("%d", &N);
	arr[0] = 3;
	for (int i = 1; i < N; i++)
	{
		arr[i] = add + arr[i-1];
		add += 3;
		ans += arr[i];
	}
	
	cout << ans;
}