#include <iostream>
using namespace::std;
long long arr[1002][2];
int main()
{
	long long w;
	long long T, a, b, p, q, n,m;
	scanf("%lld", &T);
	while (T--)
	{
		int max = 0, min = 9999;
		scanf("%lld %lld", &n, &m);
		for (int i = 1; i <= n;i++)
		{
			arr[i][0] = 0;
			arr[i][1] = 0;
		}
		while (m--)
		{
			scanf("%lld %lld %lld %lld", &a, &b, &p, &q);
			arr[a][0] += p;
			arr[b][1] += p;
			arr[b][0] += q;
			arr[a][1] += q;
		}
		for (int i = 1; i <= n; i++){
			if (arr[i][0] == 0 && arr[i][1]==0)
				w = 0;
			else
				w = 1000*arr[i][0] * arr[i][0] / (arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1]);
			if (w>max)
				max = w;
			if (min > w)
				min = w;
		}
		printf("%lld\n%lld\n", max, min);
	}
}


