#include <iostream>
#include <queue>
using namespace std;
int N, cnt = 1, answer = 98765;
int map[110][110], visit[110][110];
int di[4] = { 0,1,0,-1 }, dj[4] = { 1,0,-1,0 };
struct node {
	int _i;
	int _j;
	int _cnt;
};
queue <node> q[10000];
inline int chk(int a, int b) {
	if (a < 0 || b < 0 || a >= N || b >= N)return 0;
	return 1;
}
void dfs(int a, int b) {
	for (int i = 0; i < 4; i++) {
		int ti = a + di[i], tj = b + dj[i];
		if (chk(ti, tj) && !visit[ti][tj] && map[ti][tj]) {
			visit[ti][tj] = 1;
			map[ti][tj] = cnt;
			q[cnt].push({ ti,tj,0 });
			dfs(ti, tj);
		}
	}
}
void bfs(int C) {
	while (q[C].size())
	{
		int ni = q[C].front()._i;
		int nj = q[C].front()._j;
		int ncnt = q[C].front()._cnt;
		q[C].pop();

		for (int a = 0; a < 4; a++) {
			int ti = ni + di[a], tj = nj + dj[a];

			//다른 섬
			if (chk(ti, tj) && (map[ti][tj] != C) && map[ti][tj]) {
				if (answer > ncnt)answer = ncnt;
				return;
			}
			//빈곳 - 확장
			if (chk(ti, tj) && !visit[ti][tj] && !map[ti][tj]) {
				visit[ti][tj] = C;
				q[C].push({ ti, tj, ncnt + 1 });
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	//섬번호 부여
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] && !visit[i][j]) {
				visit[i][j] = 1;
				map[i][j] = cnt;
				q[cnt].push({ i,j,0 });
				dfs(i, j);
				cnt++;
			}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = 0;
	//
	for (int i = 1; i < cnt; i++) bfs(i);

	cout << answer;
	return 0;
}