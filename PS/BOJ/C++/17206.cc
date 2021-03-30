#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
int arr[100001];
int main() {
	//ios_base::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int N,ans=0;
		scanf("%d", &N);
		printf("%d\n",(N/3)*(N/3+1)*3/2 + (N/7)*(N/7+1)*7/2 - (N/21)*(N/21+1)/2*21 );
	}
}