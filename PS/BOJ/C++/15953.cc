#include <iostream>
#include <string>
#include <iostream>
#include <vector>
using namespace::std;
int main()
{
	int a, b, t;
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		int money = 0;
		cin >> a >> b;
		if (a == 0 || a > 21)
		{
			money += 0;
		}
		else if (a < 2) //1
		{
			money += 5000000;
		}
		else if (a < 4)//2 3
		{
			money += 3000000;
		}
		else if (a < 7)//4 5 6
		{
			money += 2000000;
		}
		else if (a < 11)
		{
			money += 500000;
		}
		else if (a < 16)
		{
			money += 300000;
		}
		else if (a < 22)
		{
			money += 100000;
		}
		if (b == 0 || b > 32)
		{
			money += 0;
		}
		else if (b < 2) //1
		{
			money += 5120000;
		}
		else if (b < 4)//2 3
		{
			money += 2560000;
		}
		else if (b < 8)//4 5 6 7
		{
			money += 1280000;
		}
		else if (b < 16)//8/9/10/11/12/13/14/15
		{
			money += 640000;
		}
		else if (b < 32)
		{
			money += 320000;
		}
		cout << money << endl;
	}
}