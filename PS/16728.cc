#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T,score =0;
	cin >> T;
	while(T--)
	{
		int x, y,d;
		cin >> x >> y;
		x = abs(x);	y = abs(y);
		d = x*x + y*y;
		for (int i = 0; i < 11; i++)
		{
			if (d <= (20 * i + 10)*(20*i+10)) {
				score += (10 - i);
				break;
			}
		}
	}
	cout << score;

}