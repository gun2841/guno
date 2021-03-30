#include <iostream>
#include <string>
using namespace::std;
int str[50][3];
int main()
{
	ios_base::sync_with_stdio(false);
	int a,cnt_a = 0, cnt_b=0,cnt_c=0;
	cin >> a;
	if (a % 10 != 0)
	{
		cout << "-1";
		return 0;
	}
	while (a != 0)
	{
		if (a >= 300)
		{
			a -= 300;
			cnt_a++;
		}
		else if (a >= 60)
		{
			a -= 60;
			cnt_b++;
		}
		else if (a >= 10)
		{
			a -= 10;
			cnt_c++;
		}
	}
	cout << cnt_a <<" "<< cnt_b<< " "<< cnt_c;
}