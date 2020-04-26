#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
using namespace::std;

int arr[51][51];
struct po
{
	int x;
	int y;
};
int curculation(po a, po b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}
int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	int ans = 100000000;
	cin >> n >> m;
	vector<po> home;
	vector<po> chiken;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			po temp;
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				temp.x = i; temp.y = j;
				chiken.push_back(temp);
			}
			else if (arr[i][j] == 1)
			{
				temp.x = i; temp.y = j;
				home.push_back(temp);
			}
		}

	vector<bool> check;
	for (int i = 0; i < chiken.size() - m; i++)
		check.push_back(false);
	for (int i = 0; i < m; i++)
		check.push_back(true);

	do
	{
		int temp = 0;
		for (int i = 0; i < home.size(); i++)
		{
			int dir = 1000000;
			for (int j = 0; j < chiken.size(); j++)
			{
				if (!check[j])
					continue;
				dir = min(dir, curculation(home[i], chiken[j]));
				
			}
			temp += dir;
		}

		ans = min(ans, temp);
	} while (next_permutation(check.begin(), check.end()));


	cout << ans;
}