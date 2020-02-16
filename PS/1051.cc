#include <iostream>
using namespace::std;
int NM[50][50];
int main()
{
	int N, M, ans=0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &NM[i][j]);
		}
	int l=0;
	if (N>M) l = M;
	else l = N;
	for (int k = l; k >= 0; k--){
		for (int i = 0; i < N - k; i++){
			for (int j = 0; j < M - k; j++)
			{
				if ((NM[i][j] == NM[i + k][j]) && (NM[i + k][j] == NM[i + k][j + k]) && (NM[i][j] == NM[i][j + k])){
					ans = k + 1;
					break;
				}
			}
			if (ans > 0)
				break;
		}
		if (ans > 0)
			break;
	}
	cout << ans*ans;
	
}