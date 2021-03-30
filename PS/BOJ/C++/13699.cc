#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	unsigned long long t[36];
	t[0] = 1;

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		unsigned long long total = 0;
		for (int j = 0; j < i; j++)
		{
			total += (t[i-j-1] * t[j]);
		}
		t[i] = total;
	}
	cout << t[n];
}