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


int main() {
	ios_base::sync_with_stdio(false);
	int n;
	int arr[4];
	int amax = -1000000000;
	int amin = 1000000000;
	cin >> n;
	vector<int> vt(n);
	for (int i = 0; i < n; i++)
		cin >> vt[i];
	for (int i = 0; i < 4; i++)
		cin >> arr[i];
	vector<int> op;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			op.push_back(i+1);
		}
	}


	do
	{
		int temp = vt[0];
		for (int i = 0; i < n-1; i++)
		{
			if (op[i] == 1)
			{
				temp += vt[i + 1];
			}
			else if (op[i] == 2)
			{
				temp -= vt[i + 1];
			}
			else if (op[i] == 3)
			{
				temp *= vt[i + 1];
			}
			else
			{
				temp /= vt[i + 1];
			}
		}
		amax = max(amax, temp);
		amin = min(amin, temp);
	} while (next_permutation(op.begin(), op.end()));

	cout << amax << endl;
	cout << amin;
}