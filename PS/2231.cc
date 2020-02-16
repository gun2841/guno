#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;
int arr[100001];
int main() {
	//ios_base::sync_with_stdio(false);
	int N , ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int total = 0;
		string str = to_string(i);
		int len = str.size();
		for (int j = 0; j < len; j++) {
			int ia = str[j] - '0';

			total +=ia;
		}

		total += i;
		if (total == N) {

			ans = i;
			break;
		}
	}
	cout << ans;
}