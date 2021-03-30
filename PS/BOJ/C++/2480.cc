#include <iostream>
using namespace std;
int main() {
	int dice[7] = { 0 };
	int test;
	for (int i = 0; i < 3; i++)
	{
		int a;
		scanf("%d", &a);
		dice[a]++;
	}
	for (int i = 1; i < 7; i++)
	{
		if (dice[i] == 3) {
			printf("%d", 10000 + 1000 * i);
			return 0;
		}
		else if (dice[i] == 2)
		{
			printf("%d", 1000 + 100 * i);
			return 0;
		}
		else if (dice[i] == 1)
			test = i;
	}
	printf("%d", test * 100);
}
