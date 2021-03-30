#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace::std;
int main()
{
	//ios_base::sync_with_stdio(false);
	float arr[5] = { 350.34,230.90,190.55,125.30,180.90 };
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		printf("$%0.2f\n", a * arr[0] + b * arr[1] + c * arr[2] + d * arr[3] + e * arr[4]);
		
	}

}
