#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;
int main()
{
	int N;
	int arr;
	vector<int> vt;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &arr);
		vt.push_back(arr);
	}
	sort(vt.begin(), vt.end());

	for (int i = 0; i < vt.size(); i++)
		printf("%d\n", vt[i]);
}