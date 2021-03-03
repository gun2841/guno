#include <iostream>
using namespace::std;
int main()
{
	//ios_base::sync_with_stdio(false);
	int h, m,total;
	cin >> h >> m;
	total = ( h * 60 + m);
	total -= 45;
	if (total < 0)
	{
		total += 1440;
		printf("%d %d", total / 60, total % 60);
	}
	else {
		printf("%d %d", total / 60, total % 60);
	}
}