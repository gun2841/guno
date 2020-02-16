#include <iostream>
#include <string>
using namespace::std;
int main()
{
	long long num, max;
	int tmp, index;
	char a;
	cin >> num >> index;
	max = index;
	while (1) {
		if (max > num)
			break;
		max *= index;
	}
	max /= index;
	while (1) {
		tmp = (num / max) % index;
		if (tmp < 10) {
			a = '0' + tmp;
			printf("%c", a);
		}
		else
		{
			a = 'A' + tmp - 10;
			printf("%c", a);
		}
		if (max == 1)
			break;
		max /= index;
	}
}
