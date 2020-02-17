#include <stdio.h>
	int arr[102][102];
	int visit[102];
	int visited[102];
	int cnt=0;
	int start=1;
	int i;
	int N=0, M=0;
void output() {
    printf("%d ", cnt-1);
    printf("\n");
}
void dfs(int start) {
    visit[cnt++] = start;
    visited[start] = 1;
 
    for (int i = 0; i <= N; i++) {
        if (arr[start][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
    return;
}
int main()
{
	int a,b,temp;
	scanf("%d", &N); // 컴퓨터의 수
	scanf("%d", &M);
	
	for(i = 1; i <= M; i++)
	{
		scanf("%d %d", &a, &b);
			arr[a][b] = 1;
			arr[b][a] = 1;
	}
	dfs(start);
	output();
}
