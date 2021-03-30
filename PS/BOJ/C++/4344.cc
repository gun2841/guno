#include <iostream>
using namespace::std;

int main()
{
	int T;
	scanf("%d", &T);
	int arr[1010];
	while (T--)
	{
		int N,cnt=0, sum = 0,x;
        float avg;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			int x;
			scanf("%d", &x);
			arr[i] = x;
			sum += x;
		}
		avg = (float)sum / (float)N;
		for (int i = 0; i < N; i++)
		{
			if ((float)arr[i] > avg)
				cnt++;
		}
		printf("%0.3f%%\n", (float)cnt / (float)N*100);
	}
}