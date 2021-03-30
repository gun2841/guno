#include <iostream>
using namespace::std;
int T, N, M, front, tfront;
int arr[101], visit[101], cnt = 0;

int main()
{
	long long max;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < N; i++) visit[i] = 0;
		scanf("%d %d", &N, &M);
		cnt = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			if (max < arr[i]) {
				max = arr[i];
				front = i;
			}
		}
		visit[front] = 1;
		while (1)
		{
			cnt++;
			tfront = front; max = -3000000000LL;
			if (front == M) {
				cout << cnt << endl;
				break;
			}
			for (int i = tfront;;)
			{
				if (visit[i] == 0) {
					if (max < arr[i]) {
						max = arr[i];
						front = i;
					}
				}
				i++;
				if (i == N) i = 0;
				if (i == tfront) break;
			}
			visit[front] = 1;
		}
	}
}