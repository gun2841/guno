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
	int tc;
	cin >> tc;
	while (tc--)
	{
		int h, w, n;
		cin >> h >> w >> n;
		int d = n % h;
		string answer="";
		if (d == 0)
			d = h;

		answer += to_string(d);
		int x = ceil( (double)n / (double)h);
		
		if (x < 10)
			answer += "0";
		answer += to_string(x);

		cout << answer << endl;
	}
}