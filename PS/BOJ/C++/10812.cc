#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;
int main()
{
	int N, M;
	vector<int> arr;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		arr.push_back(i);


	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		rotate(arr.begin()+a-1,arr.begin()+c-1,arr.begin()+b);
	}
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
}