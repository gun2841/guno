#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <cstring>
using namespace::std;
int arr[1002][1002] = { 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m,l;
	cin >> n >> m >> l;
	for(int i = 0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			int d; cin >> d;
			arr[i + 1][j + 1] = arr[i + 1][j] + arr[i][j + 1] - arr[i][j] + d;
		}

	for (int i = 0; i < l; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x = arr[c][d] - arr[a - 1][d] - arr[c][b - 1] + arr[a - 1][b - 1];
		cout << x /((c-a+1)*(d-b+1))<<"\n" ;
	}

}
