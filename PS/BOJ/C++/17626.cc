#include <iostream>
#include <string>
#include <vector>
using namespace::std;
int arr[60000] = { 0 };
void solve(int cnt, int n)
{
	if (arr[cnt] < n)
		return;
	arr[cnt] = n;
}
int main()
{
	vector<int> vt;
	for (int i = 0; i < 60000; i++)
		arr[i] = 4;
	for (int i = 1; i <= 223; i++)
	{
		arr[i * i] = 1;
		vt.push_back(i * i);
	}
	int n = vt.size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (vt[i] + vt[j] >= 50000)
				continue;
			solve(vt[i] + vt[j], 2);
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (vt[i] + vt[j] >= 50000)
				continue;
			for (int k = 0; k < n; k++)
			{
				if (vt[i] + vt[j] + vt[k] >= 50000)
					continue;
				solve(vt[i] + vt[j] + vt[k], 3);
			}
		}
	cin >> n;
	cout << arr[n];
}