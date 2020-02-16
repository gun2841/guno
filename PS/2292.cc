#include <iostream>

using namespace::std;

int main()
{
	unsigned long long n, ans=1;
	cin >> n;
	unsigned long long i = 1;
	if (n == 1)
		printf("1");
	else {
		while (n > ans)
		{
			ans += (6 * i);
			i++;
		}
		printf("%d", i);
	}
	
}