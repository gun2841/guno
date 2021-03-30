#include <iostream>
using namespace::std;
int main(void)
{
	int x;
	cin >> x;
	if (x < 60)
		printf("F");
	else if (x < 70)
		printf("D");
	else if (x < 80)
		printf("C");
	else if (x < 90)
		printf("B");
	else
		printf("A");
}