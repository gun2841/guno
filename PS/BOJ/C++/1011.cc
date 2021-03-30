#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cstring>
#include <cmath>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--)
	{
		long long a, b;
		cin >> a >> b;
		long long max = 1, n = 1,len=b-a;
		while (len > max)
		{
			max = max + n / 2 + 1;
			n++;
		}
		cout << n<<endl;
	}
}