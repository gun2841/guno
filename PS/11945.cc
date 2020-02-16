#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace::std;
int main()
{
	//ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int str[10][10];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%1d", &str[i][j]);
	}	
	for (int i = 0; i <n; i++)
	{
		for (int j = m - 1; j >= 0; j--)
			cout << str[i][j];

		cout << endl;
	}
}
