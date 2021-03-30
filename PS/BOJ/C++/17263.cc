#include <iostream>
#include <string>
#include <cmath>
#include<vector>
using namespace std;
#define ull unsigned long long
int main(int argc, char** argv)
{
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		if (a > ans)
		{
			ans = a;
		}
	}
	cout << ans;
}