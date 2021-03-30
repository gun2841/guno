#include <iostream>
using namespace::std;
int map[2188][2188] = { 0 };
int N;
int cnt_1, cnt0, cnt1;
void search(int n, int m,int temp)
{
	int s = map[n][m];
	bool check = true;
	for (int i = n; i < temp+n; i++)
		for (int j = m; j < temp+m; j++) {
			if (s != map[i][j]) {
				check = false;
				search(n, m, temp / 3);
				search(n+ temp / 3, m, temp / 3);
				search(n+ 2*temp / 3, m, temp / 3);
				search(n, m+ temp / 3, temp / 3);
				search(n+ temp / 3, m+ temp / 3, temp / 3);
				search(n+2*temp / 3, m+ temp / 3, temp / 3);
				search(n, m+2* temp / 3, temp / 3);
				search(n+ temp / 3, m+2* temp / 3, temp / 3);
				search(n+2* temp / 3, m+2* temp / 3, temp / 3);
				return;
			}
		}

	if (s == 1 && check == true)
		cnt1++;
	else if (s == 0 && check == true)
		cnt0++;
	else if (s == -1&& check == true)
		cnt_1++;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	search(0, 0, N);
	cout << cnt_1 << endl << cnt0 << endl << cnt1 << endl;
}