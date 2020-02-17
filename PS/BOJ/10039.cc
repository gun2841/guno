#include <iostream>
using namespace::std;
int main()
{
	int sum = 0;
	int score;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &score);
		if (score < 40)
			score = 40;
		sum += score;
	}
	printf("%d", sum / 5);
}