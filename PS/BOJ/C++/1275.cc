#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n, q;
	int x, y, a, b;
	vector <int> arr;
	vector <long long> res;
	scanf("%d %d", &n, &q);


	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	for (int j = 0; j<q; j++)
	{
		scanf("%d %d %d %d", &x, &y, &a, &b);
		long long sum = 0;
		if (x > y)
		{
			int temp;
			temp = x;
			x = y;
			y = temp;
		}
		for (int i = x - 1; i <= y - 1; i++)
		{
			sum += (long long)arr[i];
		}
		printf("%lld\n",sum);
		arr[a - 1] = b;
	}

	return 0;
}
